#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshVolume
struct MdIncrementalRefreshVolume {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

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
