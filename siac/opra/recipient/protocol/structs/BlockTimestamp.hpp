#pragma once

#include "../types/Seconds.hpp"
#include "../types/Nanoseconds.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct BlockTimestamp {

    Seconds seconds;
    Nanoseconds nanoseconds;

    // parse method
    static BlockTimestamp* parse(std::byte* buffer) {
        return reinterpret_cast<BlockTimestamp*>(buffer);
    }

    // parse method const
    static const BlockTimestamp* parse(const std::byte* buffer) {
        return reinterpret_cast<const BlockTimestamp*>(buffer);
    }
};

#pragma pack(pop)
}
