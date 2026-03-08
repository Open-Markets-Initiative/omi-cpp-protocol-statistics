#pragma once

#include "../types/BlockLength.hpp"
#include "../types/Padding5.hpp"
#include "../types/NumInGroup.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct GroupSize8Byte {

    sbe::BlockLength BlockLength;
    sbe::Padding5 Padding5;
    sbe::NumInGroup NumInGroup;

    // parse method
    static GroupSize8Byte* parse(std::byte* buffer) {
        return reinterpret_cast<GroupSize8Byte*>(buffer);
    }

    // parse method const
    static const GroupSize8Byte* parse(const std::byte* buffer) {
        return reinterpret_cast<const GroupSize8Byte*>(buffer);
    }
};

#pragma pack(pop)
}
