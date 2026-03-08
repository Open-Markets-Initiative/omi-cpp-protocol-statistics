#pragma once

#include "../types/MdEntryPxEx.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeStatistics.hpp"
#include "../types/Padding5.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshSessionStatisticsLongGroup {

    sbe::MdEntryPxEx MdEntryPxEx;
    sbe::MdEntrySizeOptional MdEntrySizeOptional;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::OpenCloseSettlFlag OpenCloseSettlFlag;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdEntryTypeStatistics MdEntryTypeStatistics;
    sbe::Padding5 Padding5;

    // parse method
    static IncrementalRefreshSessionStatisticsLongGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshSessionStatisticsLongGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshSessionStatisticsLongGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshSessionStatisticsLongGroup*>(buffer);
    }
};

#pragma pack(pop)
}
