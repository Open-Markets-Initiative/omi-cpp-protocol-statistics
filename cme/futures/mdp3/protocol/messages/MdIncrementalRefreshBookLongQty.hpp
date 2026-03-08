#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshBookLongQty
struct MdIncrementalRefreshBookLongQty {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

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
