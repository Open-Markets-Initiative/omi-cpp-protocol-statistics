#pragma once

#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdEntrySizeShortOptional.hpp"
#include "../types/TradeableSize.hpp"
#include "../types/NumberOfOrdersOptional.hpp"
#include "../types/MdPriceLevelOptional.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../types/MdEntryType.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../bitfields/SettlPriceType.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct SnapshotFullRefreshTcpGroup {

    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdEntrySizeShortOptional MdEntrySizeShortOptional;
    sbe::TradeableSize TradeableSize;
    sbe::NumberOfOrdersOptional NumberOfOrdersOptional;
    sbe::MdPriceLevelOptional MdPriceLevelOptional;
    sbe::OpenCloseSettlFlag OpenCloseSettlFlag;
    sbe::MdEntryType MdEntryType;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::SettlPriceType SettlPriceType;

    // parse method
    static SnapshotFullRefreshTcpGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshTcpGroup*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshTcpGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshTcpGroup*>(buffer);
    }
};

#pragma pack(pop)
}
