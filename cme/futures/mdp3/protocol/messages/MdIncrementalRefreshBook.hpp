#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshBook
struct MdIncrementalRefreshBook {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static MdIncrementalRefreshBook* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshBook*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshBook* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshBook*>(buffer);
    }
};

#pragma pack(pop)
}
