#pragma once

#include "../types/OrderIdOptional.hpp"
#include "../types/MdOrderPriorityOptional.hpp"
#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdDisplayQtyOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeBook.hpp"
#include "../types/Padding6.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshOrderBookGroup {

    sbe::OrderIdOptional OrderIdOptional;
    sbe::MdOrderPriorityOptional MdOrderPriorityOptional;
    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdDisplayQtyOptional MdDisplayQtyOptional;
    sbe::SecurityId SecurityId;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdEntryTypeBook MdEntryTypeBook;
    sbe::Padding6 Padding6;

    // parse method
    static IncrementalRefreshOrderBookGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshOrderBookGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshOrderBookGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshOrderBookGroup*>(buffer);
    }
};

#pragma pack(pop)
}
