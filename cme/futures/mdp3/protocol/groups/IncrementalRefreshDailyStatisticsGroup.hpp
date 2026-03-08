#pragma once

#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/MdEntrySizeShortOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeDailyStatistics.hpp"
#include "../types/Padding7.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshDailyStatisticsGroup {

    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::MdEntrySizeShortOptional MdEntrySizeShortOptional;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::SettlPriceType SettlPriceType;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdEntryTypeDailyStatistics MdEntryTypeDailyStatistics;
    sbe::Padding7 Padding7;

    // parse method
    static IncrementalRefreshDailyStatisticsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshDailyStatisticsGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshDailyStatisticsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshDailyStatisticsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
