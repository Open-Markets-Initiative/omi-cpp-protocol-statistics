#pragma once

#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdEntrySizeShortOptional.hpp"
#include "../types/NumberOfOrdersOptional.hpp"
#include "../types/MdPriceLevelOptional.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/MdEntryType.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct SnapshotFullRefreshGroup {

    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdEntrySizeShortOptional MdEntrySizeShortOptional;
    sbe::NumberOfOrdersOptional NumberOfOrdersOptional;
    sbe::MdPriceLevelOptional MdPriceLevelOptional;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::OpenCloseSettlFlag OpenCloseSettlFlag;
    sbe::SettlPriceType SettlPriceType;
    sbe::MdEntryType MdEntryType;

    // parse method
    static SnapshotFullRefreshGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshGroup*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshGroup*>(buffer);
    }
};

#pragma pack(pop)
}
