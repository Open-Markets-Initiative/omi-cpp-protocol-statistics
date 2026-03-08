#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDIncrementalRefreshTradeSummary
struct MdIncrementalRefreshTradeSummary {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static MdIncrementalRefreshTradeSummary* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshTradeSummary*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshTradeSummary* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshTradeSummary*>(buffer);
    }
};

#pragma pack(pop)
}
