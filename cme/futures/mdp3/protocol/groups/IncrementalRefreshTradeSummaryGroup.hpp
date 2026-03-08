#pragma once

#include "../types/MdEntryPxEx.hpp"
#include "../types/MdEntrySizeShort.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/NumberOfOrders.hpp"
#include "../types/AggressorSide.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdTradeEntryOptional.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshTradeSummaryGroup {

    sbe::MdEntryPxEx MdEntryPxEx;
    sbe::MdEntrySizeShort MdEntrySizeShort;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::NumberOfOrders NumberOfOrders;
    sbe::AggressorSide AggressorSide;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdTradeEntryOptional MdTradeEntryOptional;
    sbe::Padding2 Padding2;

    // parse method
    static IncrementalRefreshTradeSummaryGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshTradeSummaryGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshTradeSummaryGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshTradeSummaryGroup*>(buffer);
    }
};

#pragma pack(pop)
}
