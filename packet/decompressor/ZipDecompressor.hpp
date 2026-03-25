#pragma once

#ifdef HAS_ZLIB

#include "Decompressor.hpp"

#include <cstdio>
#include <cstring>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <zlib.h>

namespace packet {

// Zip local file header — parsed from a zip archive entry
struct ZipLocalHeader {
    std::uint16_t method = 0;
    std::uint32_t compressed_size = 0;
    long data_offset = 0;  // file offset where compressed data begins
    bool valid = false;

    // Parse from current file position. Returns false if no more entries.
    static ZipLocalHeader parse(FILE* fp) {
        unsigned char header[30];
        if (std::fread(header, 1, 30, fp) != 30)
            return {};

        // Check signature: PK\x03\x04
        if (header[0] != 0x50 || header[1] != 0x4b ||
            header[2] != 0x03 || header[3] != 0x04)
            return {};

        ZipLocalHeader h;
        std::memcpy(&h.method, header + 8, 2);
        std::memcpy(&h.compressed_size, header + 18, 4);

        std::uint16_t filename_len, extra_len;
        std::memcpy(&filename_len, header + 26, 2);
        std::memcpy(&extra_len, header + 28, 2);

        // Skip filename and extra field
        if (std::fseek(fp, filename_len + extra_len, SEEK_CUR) != 0)
            return {};

        h.data_offset = std::ftell(fp);
        h.valid = true;
        return h;
    }
};

// Zip entry decompressor — reads a single entry from a zip archive.
// Supports stored (method 0) and deflated (method 8) entries.
// Does NOT own the FILE* — caller manages file lifetime.
struct ZipEntryDecompressor : Decompressor {
    FILE* file_;
    z_stream stream_{};
    std::vector<Bytef> inbuf_;
    std::uint32_t compressed_remaining_ = 0;
    std::uint16_t method_ = 0;
    bool finished_ = false;
    bool inflate_initialized_ = false;

    explicit ZipEntryDecompressor(FILE* fp, const ZipLocalHeader& header,
                                   std::size_t inbuf_size = 32768)
        : file_(fp), inbuf_(inbuf_size),
          compressed_remaining_(header.compressed_size),
          method_(header.method) {
        if (method_ == 8) {
            stream_.zalloc = Z_NULL;
            stream_.zfree = Z_NULL;
            stream_.opaque = Z_NULL;
            stream_.avail_in = 0;
            stream_.next_in = Z_NULL;
            if (inflateInit2(&stream_, -MAX_WBITS) != Z_OK)
                throw std::runtime_error("inflateInit2 failed for zip entry");
            inflate_initialized_ = true;
        } else if (method_ != 0) {
            throw std::runtime_error("unsupported zip compression method: "
                                     + std::to_string(method_));
        }
    }

    ~ZipEntryDecompressor() override {
        if (inflate_initialized_) inflateEnd(&stream_);
    }

    ZipEntryDecompressor(const ZipEntryDecompressor&) = delete;
    ZipEntryDecompressor& operator=(const ZipEntryDecompressor&) = delete;

    std::size_t read(void* buf, std::size_t len) override {
        if (method_ == 0) return read_stored(buf, len);
        return read_deflated(buf, len);
    }

    bool eof() const override { return finished_; }

    // Skip remaining compressed data to position FILE* at the next entry
    void skip_remaining() {
        if (compressed_remaining_ > 0) {
            std::fseek(file_, compressed_remaining_, SEEK_CUR);
            compressed_remaining_ = 0;
        }
        finished_ = true;
    }

private:

    std::size_t read_stored(void* buf, std::size_t len) {
        if (compressed_remaining_ == 0) { finished_ = true; return 0; }

        auto to_read = std::min(len, static_cast<std::size_t>(compressed_remaining_));
        auto n = std::fread(buf, 1, to_read, file_);
        compressed_remaining_ -= static_cast<std::uint32_t>(n);
        if (n == 0) finished_ = true;
        return n;
    }

    std::size_t read_deflated(void* buf, std::size_t len) {
        stream_.next_out = static_cast<Bytef*>(buf);
        stream_.avail_out = static_cast<uInt>(len);

        while (stream_.avail_out > 0 && !finished_) {
            if (stream_.avail_in == 0 && compressed_remaining_ > 0) {
                auto to_read = std::min(
                    inbuf_.size(),
                    static_cast<std::size_t>(compressed_remaining_));
                auto n = std::fread(inbuf_.data(), 1, to_read, file_);
                if (n == 0) { finished_ = true; break; }
                compressed_remaining_ -= static_cast<std::uint32_t>(n);
                stream_.next_in = inbuf_.data();
                stream_.avail_in = static_cast<uInt>(n);
            }

            if (stream_.avail_in == 0) { finished_ = true; break; }

            int ret = inflate(&stream_, Z_NO_FLUSH);
            if (ret == Z_STREAM_END) { finished_ = true; break; }
            if (ret != Z_OK)
                throw std::runtime_error("zip inflate error: " + std::to_string(ret));
        }

        return len - stream_.avail_out;
    }
};

// open_zip_entry — opens the first entry from a zip file (takes ownership of fp)
inline std::unique_ptr<Decompressor> open_zip_entry(FILE* fp) {
    auto header = ZipLocalHeader::parse(fp);
    if (!header.valid)
        throw std::runtime_error("no valid zip entry found");
    return std::make_unique<ZipEntryDecompressor>(fp, header);
}

} // namespace packet

#endif