#pragma once

#include "../types/MessageType.hpp"
#include "../types/MessageIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/MessageDataLength.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct AdministrativeMessage {

    MessageType message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    MessageDataLength message_data_length;

    // parse method
    static AdministrativeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<AdministrativeMessage*>(buffer);
    }

    // parse method const
    static const AdministrativeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const AdministrativeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
