#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// ChannelReset
struct ChannelReset {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;

    // parse method
    static ChannelReset* parse(std::byte* buffer) {
        return reinterpret_cast<ChannelReset*>(buffer);
    }

    // parse method const
    static const ChannelReset* parse(const std::byte* buffer) {
        return reinterpret_cast<const ChannelReset*>(buffer);
    }
};

#pragma pack(pop)
}
