#pragma once

#include "../bitfields/InstAttribValue.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct InstAttribGroup {

    sbe::InstAttribValue InstAttribValue;

    // parse method
    static InstAttribGroup* parse(std::byte* buffer) {
        return reinterpret_cast<InstAttribGroup*>(buffer);
    }

    // parse method const
    static const InstAttribGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const InstAttribGroup*>(buffer);
    }
};

#pragma pack(pop)
}
