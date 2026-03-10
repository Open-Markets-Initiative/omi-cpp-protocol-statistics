#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"
#include "../types/ExecutedShares.hpp"
#include "../types/MatchNumber.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// This message is sent whenever an order on the book is executed in whole or in part
struct OrderExecutedMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    OrderReferenceNumber order_reference_number;
    ExecutedShares executed_shares;
    MatchNumber match_number;

    // parse method
    static OrderExecutedMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OrderExecutedMessage*>(buffer);
    }

    // parse method const
    static const OrderExecutedMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OrderExecutedMessage*>(buffer);
    }
};

#pragma pack(pop)
}
