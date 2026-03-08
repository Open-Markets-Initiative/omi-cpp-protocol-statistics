#pragma once

#include "../types/OrderId.hpp"
#include "../types/LastQty.hpp"
#include "../types/Padding4.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshTradeSummaryOrderIdGroup {

    sbe::OrderId OrderId;
    sbe::LastQty LastQty;
    sbe::Padding4 Padding4;

    // parse method
    static IncrementalRefreshTradeSummaryOrderIdGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshTradeSummaryOrderIdGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshTradeSummaryOrderIdGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshTradeSummaryOrderIdGroup*>(buffer);
    }
};

#pragma pack(pop)
}
