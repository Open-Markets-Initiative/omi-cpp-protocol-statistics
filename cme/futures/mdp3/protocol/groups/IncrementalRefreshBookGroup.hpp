#pragma once

#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdEntrySizeShortOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/NumberOfOrdersOptional.hpp"
#include "../types/MdPriceLevel.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeBook.hpp"
#include "../types/TradeableSize.hpp"
#include "../types/Padding1.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshBookGroup {

    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdEntrySizeShortOptional MdEntrySizeShortOptional;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::NumberOfOrdersOptional NumberOfOrdersOptional;
    sbe::MdPriceLevel MdPriceLevel;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdEntryTypeBook MdEntryTypeBook;
    sbe::TradeableSize TradeableSize;
    sbe::Padding1 Padding1;

    // parse method
    static IncrementalRefreshBookGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshBookGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshBookGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshBookGroup*>(buffer);
    }
};

#pragma pack(pop)
}
