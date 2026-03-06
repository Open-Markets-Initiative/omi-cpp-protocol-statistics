#pragma once

// Zero-copy ethernet frame dissector
// Parses: Ethernet II -> optional 802.1Q VLAN -> IPv4 -> UDP/TCP
// All pointers reference the original buffer — no copies
// Self-contained byte-order helpers via memcpy + shift-or

#include <bit>
#include <cstddef>
#include <cstdint>
#include <cstring>

namespace packet {

struct Frame {

    // --- Public fields (pre-extracted, host byte order unless noted) ---

    const std::byte* payload = nullptr;  // L4 payload start (nullptr if invalid)
    std::uint32_t payload_len = 0;       // Payload bytes
    std::uint16_t src_port = 0;          // Host byte order
    std::uint16_t dst_port = 0;          // Host byte order
    std::uint8_t  ip_protocol = 0;       // 6=TCP, 17=UDP
    std::uint16_t vlan_id = 0;           // 0 if no VLAN, else 12-bit VID
    std::uint32_t src_ip = 0;            // Network byte order
    std::uint32_t dst_ip = 0;            // Network byte order

    // --- Convenience accessors ---

    bool valid() const { return payload != nullptr; }
    bool is_udp() const { return ip_protocol == 17; }
    bool is_tcp() const { return ip_protocol == 6; }

    std::uint32_t src_ip_host() const { return swap32(src_ip); }
    std::uint32_t dst_ip_host() const { return swap32(dst_ip); }

    struct IpOctets {
        std::uint8_t a, b, c, d;
    };

    static IpOctets octets(std::uint32_t ip_net_order) {
        IpOctets o;
        std::memcpy(&o, &ip_net_order, 4);
        return o;
    }

    // --- Constructor: parse frame from raw ethernet data ---

    Frame() = default;

    Frame(const std::byte* data, std::uint32_t len)
        : data_(data), len_(len) {
        parse();
    }

    // --- Original frame access ---

    const std::byte* raw_data() const { return data_; }
    std::uint32_t raw_length() const { return len_; }

private:
    const std::byte* data_ = nullptr;
    std::uint32_t len_ = 0;

    // --- Self-contained byte-order helpers ---

    static std::uint16_t read_u16(const std::byte* p) {
        std::uint16_t val;
        std::memcpy(&val, p, sizeof(val));
        return std::byteswap(val);
    }

    static std::uint32_t read_u32(const std::byte* p) {
        return (static_cast<std::uint32_t>(p[0]) << 24)
             | (static_cast<std::uint32_t>(p[1]) << 16)
             | (static_cast<std::uint32_t>(p[2]) << 8)
             |  static_cast<std::uint32_t>(p[3]);
    }

    static std::uint32_t swap32(std::uint32_t v) {
        return ((v >> 24) & 0xFF)
             | ((v >>  8) & 0xFF00)
             | ((v <<  8) & 0xFF0000)
             | ((v << 24) & 0xFF000000u);
    }

    // --- Parse logic ---

    void parse() {
        // Minimum ethernet frame: 14 bytes (6 dst + 6 src + 2 ethertype)
        if (!data_ || len_ < 14) return;

        std::uint32_t offset = 12;
        auto ethertype = read_u16(data_ + offset);
        offset += 2;

        // 802.1Q VLAN tag
        if (ethertype == 0x8100) {
            if (len_ < offset + 4) return;
            auto tci = read_u16(data_ + offset);
            vlan_id = tci & 0x0FFF;
            ethertype = read_u16(data_ + offset + 2);
            offset += 4;
        }

        // Only IPv4
        if (ethertype != 0x0800) return;

        // IPv4 header: minimum 20 bytes
        auto ip_start = offset;
        if (len_ < ip_start + 20) return;

        auto ihl_byte = static_cast<std::uint8_t>(data_[ip_start]);
        auto ip_version = (ihl_byte >> 4) & 0x0F;
        if (ip_version != 4) return;

        auto ip_hdr_len = static_cast<std::uint32_t>(ihl_byte & 0x0F) * 4;
        if (ip_hdr_len < 20) return;
        if (len_ < ip_start + ip_hdr_len) return;

        auto ip_total_len = static_cast<std::uint32_t>(read_u16(data_ + ip_start + 2));

        // Clamp to capture length (truncated captures stay valid)
        auto available = len_ - ip_start;
        if (ip_total_len > available) ip_total_len = available;

        ip_protocol = static_cast<std::uint8_t>(data_[ip_start + 9]);

        // src_ip and dst_ip in network byte order (raw memcpy)
        std::memcpy(&src_ip, data_ + ip_start + 12, 4);
        std::memcpy(&dst_ip, data_ + ip_start + 16, 4);

        auto l4_start = ip_start + ip_hdr_len;

        if (ip_protocol == 17) {
            // UDP: 8-byte header
            if (ip_total_len < ip_hdr_len + 8) return;
            if (len_ < l4_start + 8) return;

            src_port = read_u16(data_ + l4_start);
            dst_port = read_u16(data_ + l4_start + 2);

            auto udp_len = static_cast<std::uint32_t>(read_u16(data_ + l4_start + 4));

            // Clamp UDP length to IP total length
            auto max_udp = ip_total_len - ip_hdr_len;
            if (udp_len > max_udp) udp_len = max_udp;

            payload = data_ + l4_start + 8;
            payload_len = (udp_len >= 8) ? (udp_len - 8) : 0;

        } else if (ip_protocol == 6) {
            // TCP: variable header (minimum 20 bytes)
            if (ip_total_len < ip_hdr_len + 20) return;
            if (len_ < l4_start + 20) return;

            src_port = read_u16(data_ + l4_start);
            dst_port = read_u16(data_ + l4_start + 2);

            auto data_offset_byte = static_cast<std::uint8_t>(data_[l4_start + 12]);
            auto tcp_hdr_len = static_cast<std::uint32_t>((data_offset_byte >> 4) & 0x0F) * 4;
            if (tcp_hdr_len < 20) return;
            if (len_ < l4_start + tcp_hdr_len) return;

            payload = data_ + l4_start + tcp_hdr_len;
            auto ip_payload = ip_total_len - ip_hdr_len;
            payload_len = (ip_payload > tcp_hdr_len) ? (ip_payload - tcp_hdr_len) : 0;
        }
        // Other protocols: payload stays nullptr
    }
};

} // namespace packet