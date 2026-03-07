#pragma once

#include "../bitfields/SaleConditionFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/OrderIdReference.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"
#include "../types/TradeId.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// A displayed order that was executed against
struct OrderExecutedMessage {

    iextp::SaleConditionFlags SaleConditionFlags;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;
    iextp::OrderIdReference OrderIdReference;
    iextp::Size Size;
    iextp::Price Price;
    iextp::TradeId TradeId;

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
