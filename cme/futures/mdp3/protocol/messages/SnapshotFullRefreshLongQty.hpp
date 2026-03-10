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

#pragma pack(push, 1)

// SnapshotFullRefreshLongQty
struct SnapshotFullRefreshLongQty {

    LastMsgSeqNumProcessed last_msg_seq_num_processed;
    TotNumReports tot_num_reports;
    SecurityId security_id;
    RptSeq rpt_seq;
    TransactTime transact_time;
    LastUpdateTime last_update_time;
    TradeDate trade_date;
    MdSecurityTradingStatus md_security_trading_status;
    HighLimitPrice high_limit_price;
    LowLimitPrice low_limit_price;
    MaxPriceVariation max_price_variation;

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
