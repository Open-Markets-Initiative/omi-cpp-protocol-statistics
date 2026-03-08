#pragma once

#include "../types/PacketSequenceNumber.hpp"
#include "../types/SendingTime.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct BinaryPacketHeader {

    sbe::PacketSequenceNumber PacketSequenceNumber;
    sbe::SendingTime SendingTime;

    // parse method
    static BinaryPacketHeader* parse(std::byte* buffer) {
        return reinterpret_cast<BinaryPacketHeader*>(buffer);
    }

    // parse method const
    static const BinaryPacketHeader* parse(const std::byte* buffer) {
        return reinterpret_cast<const BinaryPacketHeader*>(buffer);
    }
};

#pragma pack(pop)
}
