#pragma once

#include "../types/Text.hpp"

namespace cme::mdp3::v13 {

#pragma pack(push, 1)

// AdminLogout
struct AdminLogout {

    Text text;

    // parse method
    static AdminLogout* parse(std::byte* buffer) {
        return reinterpret_cast<AdminLogout*>(buffer);
    }

    // parse method const
    static const AdminLogout* parse(const std::byte* buffer) {
        return reinterpret_cast<const AdminLogout*>(buffer);
    }
};

#pragma pack(pop)
}
