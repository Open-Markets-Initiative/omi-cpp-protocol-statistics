#pragma once

#include "../types/ControlMessageType.hpp"
#include "../types/MessageIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/MessageDataLength.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct ControlMessage {

    ControlMessageType control_message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    MessageDataLength message_data_length;

    // parse method
    static ControlMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ControlMessage*>(buffer);
    }

    // parse method const
    static const ControlMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ControlMessage*>(buffer);
    }
};

#pragma pack(pop)
}
