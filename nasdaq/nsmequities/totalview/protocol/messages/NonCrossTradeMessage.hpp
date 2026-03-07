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

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Trade Messages should be included in NASDAQ time-and-sales displays as well as volume and other market statistics
struct NonCrossTradeMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::OrderReferenceNumber OrderReferenceNumber;
    itch::BuySellIndicator BuySellIndicator;
    itch::Shares Shares;
    itch::Stock Stock;
    itch::Price Price;
    itch::MatchNumber MatchNumber;

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
