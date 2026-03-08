#pragma once

#include "../types/OrderId.hpp"
#include "../types/MdOrderPriority.hpp"
#include "../types/MdEntryPxEx.hpp"
#include "../types/MdDisplayQty.hpp"
#include "../types/MdEntryTypeBook.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct SnapshotRefreshTopOrdersGroup {

    sbe::OrderId OrderId;
    sbe::MdOrderPriority MdOrderPriority;
    sbe::MdEntryPxEx MdEntryPxEx;
    sbe::MdDisplayQty MdDisplayQty;
    sbe::MdEntryTypeBook MdEntryTypeBook;

    // parse method
    static SnapshotRefreshTopOrdersGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotRefreshTopOrdersGroup*>(buffer);
    }

    // parse method const
    static const SnapshotRefreshTopOrdersGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotRefreshTopOrdersGroup*>(buffer);
    }
};

#pragma pack(pop)
}
