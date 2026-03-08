#pragma once

#include "../types/BlockLength.hpp"
#include "../types/TemplateId.hpp"
#include "../types/SchemaId.hpp"
#include "../types/Version.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct MessageHeader {

    sbe::BlockLength BlockLength;
    sbe::TemplateId TemplateId;
    sbe::SchemaId SchemaId;
    sbe::Version Version;

    // parse method
    static MessageHeader* parse(std::byte* buffer) {
        return reinterpret_cast<MessageHeader*>(buffer);
    }

    // parse method const
    static const MessageHeader* parse(const std::byte* buffer) {
        return reinterpret_cast<const MessageHeader*>(buffer);
    }
};

#pragma pack(pop)
}
