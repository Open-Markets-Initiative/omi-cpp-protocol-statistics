#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshOrderBook
struct MdIncrementalRefreshOrderBook {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

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
