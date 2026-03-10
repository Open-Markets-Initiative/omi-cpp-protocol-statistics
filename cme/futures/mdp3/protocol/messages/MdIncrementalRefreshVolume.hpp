#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// MDIncrementalRefreshVolume
struct MdIncrementalRefreshVolume {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

    // parse method
    static MdIncrementalRefreshVolume* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshVolume*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshVolume* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshVolume*>(buffer);
    }
};

#pragma pack(pop)
}
