#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/SecurityId.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// SnapshotFullRefreshTCP
struct SnapshotFullRefreshTcp {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::SecurityId SecurityId;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;

    // parse method
    static SnapshotFullRefreshTcp* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshTcp*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshTcp* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshTcp*>(buffer);
    }
};

#pragma pack(pop)
}
