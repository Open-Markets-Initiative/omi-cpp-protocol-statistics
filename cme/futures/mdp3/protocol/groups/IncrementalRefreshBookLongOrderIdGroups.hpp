#pragma once

#include "../types/OrderId.hpp"
#include "../types/MdOrderPriorityOptional.hpp"
#include "../types/MdDisplayQtyOptional.hpp"
#include "../types/ReferenceId.hpp"
#include "../types/OrderUpdateAction.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshBookLongOrderIdGroups {

    sbe::OrderId OrderId;
    sbe::MdOrderPriorityOptional MdOrderPriorityOptional;
    sbe::MdDisplayQtyOptional MdDisplayQtyOptional;
    sbe::ReferenceId ReferenceId;
    sbe::OrderUpdateAction OrderUpdateAction;
    sbe::Padding2 Padding2;

    // parse method
    static IncrementalRefreshBookLongOrderIdGroups* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshBookLongOrderIdGroups*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshBookLongOrderIdGroups* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshBookLongOrderIdGroups*>(buffer);
    }
};

#pragma pack(pop)
}
