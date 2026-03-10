#pragma once

#include "../types/SystemEvent.hpp"
#include "../types/Timestamp.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

#pragma pack(push, 1)

// The System Event Message is used to indicate events that apply to the market or the data feed.
struct SystemEventMessage {

    SystemEvent system_event;
    Timestamp timestamp;

    // parse method
    static SystemEventMessage* parse(std::byte* buffer) {
        return reinterpret_cast<SystemEventMessage*>(buffer);
    }

    // parse method const
    static const SystemEventMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const SystemEventMessage*>(buffer);
    }
};

#pragma pack(pop)
}
