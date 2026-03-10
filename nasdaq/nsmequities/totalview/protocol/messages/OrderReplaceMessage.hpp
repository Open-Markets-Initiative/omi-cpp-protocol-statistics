#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OriginalOrderReferenceNumber.hpp"
#include "../types/NewOrderReferenceNumber.hpp"
#include "../types/Shares.hpp"
#include "../types/Price.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// This message is sent whenever an order on the book has been cancel-replaced
struct OrderReplaceMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    OriginalOrderReferenceNumber original_order_reference_number;
    NewOrderReferenceNumber new_order_reference_number;
    Shares shares;
    Price price;

    // parse method
    static OrderReplaceMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OrderReplaceMessage*>(buffer);
    }

    // parse method const
    static const OrderReplaceMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OrderReplaceMessage*>(buffer);
    }
};

#pragma pack(pop)
}
