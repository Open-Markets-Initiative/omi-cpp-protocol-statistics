#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshSessionStatisticsLongQty
struct MdIncrementalRefreshSessionStatisticsLongQty {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static MdIncrementalRefreshSessionStatisticsLongQty* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshSessionStatisticsLongQty*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshSessionStatisticsLongQty* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshSessionStatisticsLongQty*>(buffer);
    }
};

#pragma pack(pop)
}
