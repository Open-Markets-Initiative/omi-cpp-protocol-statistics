#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshBookLongQty
struct MdIncrementalRefreshBookLongQty {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

    // parse method
    static MdIncrementalRefreshBookLongQty* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshBookLongQty*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshBookLongQty* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshBookLongQty*>(buffer);
    }
};

#pragma pack(pop)
}
