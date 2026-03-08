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

// SnapshotFullRefreshTCPLongQty
struct SnapshotFullRefreshTcpLongQty {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::SecurityId SecurityId;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;

    // parse method
    static SnapshotFullRefreshTcpLongQty* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshTcpLongQty*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshTcpLongQty* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshTcpLongQty*>(buffer);
    }
};

#pragma pack(pop)
}
