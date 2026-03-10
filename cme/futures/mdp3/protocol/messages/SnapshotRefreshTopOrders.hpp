#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/SecurityId.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// SnapshotRefreshTopOrders
struct SnapshotRefreshTopOrders {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    SecurityId security_id;

    // parse method
    static SnapshotRefreshTopOrders* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotRefreshTopOrders*>(buffer);
    }

    // parse method const
    static const SnapshotRefreshTopOrders* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotRefreshTopOrders*>(buffer);
    }
};

#pragma pack(pop)
}
