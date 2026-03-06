#pragma once

#include "../bitfields/ModifyFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/OrderIdReference.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// A displayed order that had its Price, Size, or Priority component changed as a result of user or system action
struct OrderModifyMessage {

    iextp::ModifyFlags ModifyFlags;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;
    iextp::OrderIdReference OrderIdReference;
    iextp::Size Size;
    iextp::Price Price;

    // parse method
    static OrderModifyMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OrderModifyMessage*>(buffer);
    }

    // parse method const
    static const OrderModifyMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OrderModifyMessage*>(buffer);
    }
};

#pragma pack(pop)
}
