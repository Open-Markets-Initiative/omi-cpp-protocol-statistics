#pragma once

#include "../types/MdEntryPxEx.hpp"
#include "../types/MdEntrySize.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/NumberOfOrders.hpp"
#include "../types/MdTradeEntry.hpp"
#include "../types/AggressorSide.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/Padding6.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshTradeSummaryLongGroup {

    sbe::MdEntryPxEx MdEntryPxEx;
    sbe::MdEntrySize MdEntrySize;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::NumberOfOrders NumberOfOrders;
    sbe::MdTradeEntry MdTradeEntry;
    sbe::AggressorSide AggressorSide;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::Padding6 Padding6;

    // parse method
    static IncrementalRefreshTradeSummaryLongGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshTradeSummaryLongGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshTradeSummaryLongGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshTradeSummaryLongGroup*>(buffer);
    }
};

#pragma pack(pop)
}
