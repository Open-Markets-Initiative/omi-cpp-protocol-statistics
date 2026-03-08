#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshTradeSummaryLongQty
struct MdIncrementalRefreshTradeSummaryLongQty {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static MdIncrementalRefreshTradeSummaryLongQty* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshTradeSummaryLongQty*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshTradeSummaryLongQty* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshTradeSummaryLongQty*>(buffer);
    }
};

#pragma pack(pop)
}
