#pragma once

#include "../types/Reserved1.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/OrderIdReference.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

#pragma pack(push, 1)

// A displayed order that was removed from the IEX Book
struct OrderDeleteMessage {

    Reserved1 reserved_1;
    Timestamp timestamp;
    Symbol symbol;
    OrderIdReference order_id_reference;

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
