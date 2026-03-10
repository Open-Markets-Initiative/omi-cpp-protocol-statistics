#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshSessionStatistics
struct MdIncrementalRefreshSessionStatistics {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

    // parse method
    static MdIncrementalRefreshSessionStatistics* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshSessionStatistics*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshSessionStatistics* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshSessionStatistics*>(buffer);
    }
};

#pragma pack(pop)
}
