#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/SecurityId.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// SnapshotFullRefreshTCPLongQty
struct SnapshotFullRefreshTcpLongQty {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    SecurityId security_id;
    HighLimitPrice high_limit_price;
    LowLimitPrice low_limit_price;
    MaxPriceVariation max_price_variation;

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
