#pragma once

#include "../types/HeartBtInt.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// AdminLogin
struct AdminLogin {

    sbe::HeartBtInt HeartBtInt;

    // parse method
    static AdminLogin* parse(std::byte* buffer) {
        return reinterpret_cast<AdminLogin*>(buffer);
    }

    // parse method const
    static const AdminLogin* parse(const std::byte* buffer) {
        return reinterpret_cast<const AdminLogin*>(buffer);
    }
};

#pragma pack(pop)
}
