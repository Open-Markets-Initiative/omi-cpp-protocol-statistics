#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshVolumeLongQty
struct MdIncrementalRefreshVolumeLongQty {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static MdIncrementalRefreshVolumeLongQty* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshVolumeLongQty*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshVolumeLongQty* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshVolumeLongQty*>(buffer);
    }
};

#pragma pack(pop)
}
