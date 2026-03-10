#pragma once

#include "../types/OrderId.hpp"
#include "../types/MdOrderPriorityOptional.hpp"
#include "../types/MdDisplayQtyOptional.hpp"
#include "../types/ReferenceId.hpp"
#include "../types/OrderUpdateAction.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

struct IncrementalRefreshBookLongOrderIdGroups {

    OrderId order_id;
    MdOrderPriorityOptional md_order_priority_optional;
    MdDisplayQtyOptional md_display_qty_optional;
    ReferenceId reference_id;
    OrderUpdateAction order_update_action;
    Padding2 padding_2;

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
