#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// This message is sent whenever an order on the book is being cancelled
struct OrderDeleteMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    OrderReferenceNumber order_reference_number;

    // parse method
    static OrderDeleteMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OrderDeleteMessage*>(buffer);
    }

    // parse method const
    static const OrderDeleteMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OrderDeleteMessage*>(buffer);
    }
};

#pragma pack(pop)
}
