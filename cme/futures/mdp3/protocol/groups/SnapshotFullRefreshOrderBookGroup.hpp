#pragma once

#include "../types/OrderId.hpp"
#include "../types/MdOrderPriorityOptional.hpp"
#include "../types/MdEntryPxEx.hpp"
#include "../types/MdDisplayQty.hpp"
#include "../types/MdEntryTypeBook.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct SnapshotFullRefreshOrderBookGroup {

    sbe::OrderId OrderId;
    sbe::MdOrderPriorityOptional MdOrderPriorityOptional;
    sbe::MdEntryPxEx MdEntryPxEx;
    sbe::MdDisplayQty MdDisplayQty;
    sbe::MdEntryTypeBook MdEntryTypeBook;

    // parse method
    static SnapshotFullRefreshOrderBookGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshOrderBookGroup*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshOrderBookGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshOrderBookGroup*>(buffer);
    }
};

#pragma pack(pop)
}
