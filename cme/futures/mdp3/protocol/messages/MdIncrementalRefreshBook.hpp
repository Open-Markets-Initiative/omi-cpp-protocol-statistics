#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshBook
struct MdIncrementalRefreshBook {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

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
