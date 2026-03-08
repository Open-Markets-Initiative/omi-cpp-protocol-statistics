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

struct IncrementalRefreshBookOrderIdGroup {

    sbe::OrderId OrderId;
    sbe::MdOrderPriorityOptional MdOrderPriorityOptional;
    sbe::MdDisplayQtyOptional MdDisplayQtyOptional;
    sbe::ReferenceId ReferenceId;
    sbe::OrderUpdateAction OrderUpdateAction;
    sbe::Padding2 Padding2;

    // parse method
    static IncrementalRefreshBookOrderIdGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshBookOrderIdGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshBookOrderIdGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshBookOrderIdGroup*>(buffer);
    }
};

#pragma pack(pop)
}
