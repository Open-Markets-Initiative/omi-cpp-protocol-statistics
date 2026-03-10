#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshLimitsBanding
struct MdIncrementalRefreshLimitsBanding {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

    // parse method
    static MdIncrementalRefreshLimitsBanding* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshLimitsBanding*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshLimitsBanding* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshLimitsBanding*>(buffer);
    }
};

#pragma pack(pop)
}
