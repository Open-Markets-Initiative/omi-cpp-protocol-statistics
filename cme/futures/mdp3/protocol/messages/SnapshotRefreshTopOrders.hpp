#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/SecurityId.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// SnapshotRefreshTopOrders
struct SnapshotRefreshTopOrders {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::SecurityId SecurityId;

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
