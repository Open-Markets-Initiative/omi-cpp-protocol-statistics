#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"
#include "../types/BuySellIndicator.hpp"
#include "../types/Shares.hpp"
#include "../types/Stock.hpp"
#include "../types/Price.hpp"
#include "../types/Attribution.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// This message will be generated for attributed orders and quotations accepted by the Nasdaq system
struct AddOrderWithMpidAttributionMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    OrderReferenceNumber order_reference_number;
    BuySellIndicator buy_sell_indicator;
    Shares shares;
    Stock stock;
    Price price;
    Attribution attribution;

    // parse method
    static AddOrderWithMpidAttributionMessage* parse(std::byte* buffer) {
        return reinterpret_cast<AddOrderWithMpidAttributionMessage*>(buffer);
    }

    // parse method const
    static const AddOrderWithMpidAttributionMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const AddOrderWithMpidAttributionMessage*>(buffer);
    }
};

#pragma pack(pop)
}
