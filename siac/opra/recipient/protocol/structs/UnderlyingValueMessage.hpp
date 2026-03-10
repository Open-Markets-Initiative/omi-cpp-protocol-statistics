#pragma once

#include "../types/UnderlyingValueMessageType.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct UnderlyingValueMessage {

    UnderlyingValueMessageType underlying_value_message_type;

    // parse method
    static UnderlyingValueMessage* parse(std::byte* buffer) {
        return reinterpret_cast<UnderlyingValueMessage*>(buffer);
    }

    // parse method const
    static const UnderlyingValueMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const UnderlyingValueMessage*>(buffer);
    }
};

#pragma pack(pop)
}
