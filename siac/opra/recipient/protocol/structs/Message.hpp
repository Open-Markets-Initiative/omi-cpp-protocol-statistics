#pragma once

#include "../types/ParticipantId.hpp"
#include "../types/MessageCategory.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct Message {

    ParticipantId participant_id;
    MessageCategory message_category;

    // parse method
    static Message* parse(std::byte* buffer) {
        return reinterpret_cast<Message*>(buffer);
    }

    // parse method const
    static const Message* parse(const std::byte* buffer) {
        return reinterpret_cast<const Message*>(buffer);
    }
};

#pragma pack(pop)
}
