#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/InterestFlag.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Identifies a retail interest indication of the Bid, Ask or both the Bid and Ask for NASDAQ-listed securities.
struct RetailPriceImprovementIndicatorMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    Stock stock;
    InterestFlag interest_flag;

    // parse method
    static RetailPriceImprovementIndicatorMessage* parse(std::byte* buffer) {
        return reinterpret_cast<RetailPriceImprovementIndicatorMessage*>(buffer);
    }

    // parse method const
    static const RetailPriceImprovementIndicatorMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const RetailPriceImprovementIndicatorMessage*>(buffer);
    }
};

#pragma pack(pop)
}
