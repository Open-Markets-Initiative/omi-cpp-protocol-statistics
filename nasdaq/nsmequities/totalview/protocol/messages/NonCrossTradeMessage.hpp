#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"
#include "../types/BuySellIndicator.hpp"
#include "../types/Shares.hpp"
#include "../types/Stock.hpp"
#include "../types/Price.hpp"
#include "../types/MatchNumber.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Trade Messages should be included in NASDAQ time-and-sales displays as well as volume and other market statistics
struct NonCrossTradeMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    OrderReferenceNumber order_reference_number;
    BuySellIndicator buy_sell_indicator;
    Shares shares;
    Stock stock;
    Price price;
    MatchNumber match_number;

    // parse method
    static NonCrossTradeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<NonCrossTradeMessage*>(buffer);
    }

    // parse method const
    static const NonCrossTradeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const NonCrossTradeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
