#pragma once

#include "../definitions.hpp"

namespace cme::mdp3::v13 {
// MessageIterator
struct MessageIterator {

    const std::byte* current = nullptr;
    const std::byte* end = nullptr;

    std::uint16_t template_id = 0;
    std::uint16_t message_size = 0;
    const std::byte* message = nullptr;

    // initialize parser
    void initialize(const std::byte* data, std::size_t length) {

        end = data + length;

        if (length < sizeof(BinaryPacketHeader)) {
            current = end;
            message = nullptr;
            template_id = 0;
            message_size = 0;
            return;
        }

        current = data + sizeof(BinaryPacketHeader);
        message = nullptr;

        template_id = 0;
        message_size = 0;
    }

    // next message
    bool next() {

        if (current >= end) {
            return false;
        }

        if (current + sizeof(Message) > end) {
            return false;
        }

        const auto* header = Message::parse(current);
        message = current + sizeof(Message);

        template_id = header->MessageHeader.TemplateId.get();
        message_size = header->MessageSize.get();

        current += message_size;

        return true;
    }

    // reset iterator
    void reset() {
        current = nullptr;
        end = nullptr;

        message = nullptr;
        template_id = 0;
        message_size = 0;
    }
};
}
