#pragma once

#include "../types/LastMsgSeqNumProcessed.hpp"
#include "../types/TotNumReports.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/TransactTime.hpp"
#include "../types/LastUpdateTime.hpp"
#include "../types/TradeDate.hpp"
#include "../types/MdSecurityTradingStatus.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// SnapshotFullRefreshLongQty
struct SnapshotFullRefreshLongQty {

    sbe::LastMsgSeqNumProcessed LastMsgSeqNumProcessed;
    sbe::TotNumReports TotNumReports;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::TransactTime TransactTime;
    sbe::LastUpdateTime LastUpdateTime;
    sbe::TradeDate TradeDate;
    sbe::MdSecurityTradingStatus MdSecurityTradingStatus;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;

    // parse method
    static SnapshotFullRefreshLongQty* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshLongQty*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshLongQty* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshLongQty*>(buffer);
    }
};

#pragma pack(pop)
}
