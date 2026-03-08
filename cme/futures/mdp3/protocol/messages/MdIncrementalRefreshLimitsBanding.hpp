#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshLimitsBanding
struct MdIncrementalRefreshLimitsBanding {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

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
