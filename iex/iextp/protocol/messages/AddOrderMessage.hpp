#pragma once

#include "../types/Side.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/OrderId.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// A displayed order that has been added to the IEX Book
struct AddOrderMessage {

    iextp::Side Side;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;
    iextp::OrderId OrderId;
    iextp::Size Size;
    iextp::Price Price;

    // parse method
    static AddOrderMessage* parse(std::byte* buffer) {
        return reinterpret_cast<AddOrderMessage*>(buffer);
    }

    // parse method const
    static const AddOrderMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const AddOrderMessage*>(buffer);
    }
};

#pragma pack(pop)
}
