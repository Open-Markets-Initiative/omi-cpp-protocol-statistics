#pragma once

#include "../types/ApplId.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct ChannelResetGroup {

    sbe::ApplId ApplId;

    // parse method
    static ChannelResetGroup* parse(std::byte* buffer) {
        return reinterpret_cast<ChannelResetGroup*>(buffer);
    }

    // parse method const
    static const ChannelResetGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const ChannelResetGroup*>(buffer);
    }
};

#pragma pack(pop)
}
