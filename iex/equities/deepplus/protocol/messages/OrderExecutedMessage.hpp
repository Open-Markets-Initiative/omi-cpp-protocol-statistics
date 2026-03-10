#pragma once

#include "../bitfields/SaleConditionFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/OrderIdReference.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"
#include "../types/TradeId.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

#pragma pack(push, 1)

// A displayed order that was executed against
struct OrderExecutedMessage {

    SaleConditionFlags sale_condition_flags;
    Timestamp timestamp;
    Symbol symbol;
    OrderIdReference order_id_reference;
    Size size;
    Price price;
    TradeId trade_id;

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
