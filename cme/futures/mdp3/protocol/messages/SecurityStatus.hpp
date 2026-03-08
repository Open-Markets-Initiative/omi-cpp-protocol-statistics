#pragma once

#include "../types/TransactTime.hpp"
#include "../types/SecurityGroup.hpp"
#include "../types/Asset.hpp"
#include "../types/SecurityIdOptional.hpp"
#include "../types/TradeDate.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/SecurityTradingStatus.hpp"
#include "../types/HaltReason.hpp"
#include "../types/SecurityTradingEvent.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// SecurityStatus
struct SecurityStatus {

    sbe::TransactTime TransactTime;
    sbe::SecurityGroup SecurityGroup;
    sbe::Asset Asset;
    sbe::SecurityIdOptional SecurityIdOptional;
    sbe::TradeDate TradeDate;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::SecurityTradingStatus SecurityTradingStatus;
    sbe::HaltReason HaltReason;
    sbe::SecurityTradingEvent SecurityTradingEvent;

    // parse method
    static SecurityStatus* parse(std::byte* buffer) {
        return reinterpret_cast<SecurityStatus*>(buffer);
    }

    // parse method const
    static const SecurityStatus* parse(const std::byte* buffer) {
        return reinterpret_cast<const SecurityStatus*>(buffer);
    }
};

#pragma pack(pop)
}
