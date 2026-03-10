#pragma once

#include "../types/SecurityEvent.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

#pragma pack(push, 1)

// The Security Event Message is used to indicate events that apply to a security
struct SecurityEventMessage {

    SecurityEvent security_event;
    Timestamp timestamp;
    Symbol symbol;

    // parse method
    static SecurityEventMessage* parse(std::byte* buffer) {
        return reinterpret_cast<SecurityEventMessage*>(buffer);
    }

    // parse method const
    static const SecurityEventMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const SecurityEventMessage*>(buffer);
    }
};

#pragma pack(pop)
}
