#pragma once

#include "../types/MdEntryPxEx.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeStatistics.hpp"
#include "../types/MdEntrySizeShortOptional.hpp"
#include "../types/Padding1.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshSessionStatisticsGroup {

    sbe::MdEntryPxEx MdEntryPxEx;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::OpenCloseSettlFlag OpenCloseSettlFlag;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::MdEntryTypeStatistics MdEntryTypeStatistics;
    sbe::MdEntrySizeShortOptional MdEntrySizeShortOptional;
    sbe::Padding1 Padding1;

    // parse method
    static IncrementalRefreshSessionStatisticsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshSessionStatisticsGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshSessionStatisticsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshSessionStatisticsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
