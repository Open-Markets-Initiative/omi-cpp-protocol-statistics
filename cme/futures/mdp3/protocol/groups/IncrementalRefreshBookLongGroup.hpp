#pragma once

#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/NumberOfOrdersOptional.hpp"
#include "../types/MdPriceLevel.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeBook.hpp"
#include "../types/Padding1.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshBookLongGroup {

    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdEntrySizeOptional MdEntrySizeOptional;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::NumberOfOrdersOptional NumberOfOrdersOptional;
    sbe::MdPriceLevel MdPriceLevel;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdEntryTypeBook MdEntryTypeBook;
    sbe::Padding1 Padding1;

    // parse method
    static IncrementalRefreshBookLongGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshBookLongGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshBookLongGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshBookLongGroup*>(buffer);
    }
};

#pragma pack(pop)
}
