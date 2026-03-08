#pragma once

#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/NumberOfOrdersOptional.hpp"
#include "../types/MdPriceLevelUnsignedOptional.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../types/MdEntryType.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct SnapshotFullRefreshLongGroup {

    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdEntrySizeOptional MdEntrySizeOptional;
    sbe::NumberOfOrdersOptional NumberOfOrdersOptional;
    sbe::MdPriceLevelUnsignedOptional MdPriceLevelUnsignedOptional;
    sbe::OpenCloseSettlFlag OpenCloseSettlFlag;
    sbe::MdEntryType MdEntryType;

    // parse method
    static SnapshotFullRefreshLongGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshLongGroup*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshLongGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshLongGroup*>(buffer);
    }
};

#pragma pack(pop)
}
