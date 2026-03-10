#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshTradeSummary
struct MdIncrementalRefreshTradeSummary {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

    // parse method
    static MdIncrementalRefreshTradeSummary* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshTradeSummary*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshTradeSummary* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshTradeSummary*>(buffer);
    }
};

#pragma pack(pop)
}
