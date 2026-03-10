#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"
#include "../types/ExecutedShares.hpp"
#include "../types/MatchNumber.hpp"
#include "../types/Printable.hpp"
#include "../types/ExecutionPrice.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// This message is sent whenever an order on the book is executed in whole or in part at a price different from the initial display price
struct OrderExecutedWithPriceMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    OrderReferenceNumber order_reference_number;
    ExecutedShares executed_shares;
    MatchNumber match_number;
    Printable printable;
    ExecutionPrice execution_price;

    // parse method
    static OrderExecutedWithPriceMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OrderExecutedWithPriceMessage*>(buffer);
    }

    // parse method const
    static const OrderExecutedWithPriceMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OrderExecutedWithPriceMessage*>(buffer);
    }
};

#pragma pack(pop)
}
