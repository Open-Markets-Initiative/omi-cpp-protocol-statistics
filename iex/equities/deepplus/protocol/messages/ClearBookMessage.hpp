#pragma once

#include "../types/Reserved1.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// This message is used to indicate that the IEX Book for a symbol has been cleared of all orders
struct ClearBookMessage {

    iextp::Reserved1 Reserved1;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;

    // parse method
    static ClearBookMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ClearBookMessage*>(buffer);
    }

    // parse method const
    static const ClearBookMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ClearBookMessage*>(buffer);
    }
};

#pragma pack(pop)
}
