#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshOrderBook
struct MdIncrementalRefreshOrderBook {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static MdIncrementalRefreshOrderBook* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshOrderBook*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshOrderBook* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshOrderBook*>(buffer);
    }
};

#pragma pack(pop)
}
