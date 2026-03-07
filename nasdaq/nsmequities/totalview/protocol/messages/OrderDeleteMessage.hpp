#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// This message is sent whenever an order on the book is being cancelled
struct OrderDeleteMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::OrderReferenceNumber OrderReferenceNumber;

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
