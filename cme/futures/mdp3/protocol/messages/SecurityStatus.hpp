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

#pragma pack(push, 1)

// SecurityStatus
struct SecurityStatus {

    TransactTime transact_time;
    SecurityGroup security_group;
    Asset asset;
    SecurityIdOptional security_id_optional;
    TradeDate trade_date;
    MatchEventIndicator match_event_indicator;
    SecurityTradingStatus security_trading_status;
    HaltReason halt_reason;
    SecurityTradingEvent security_trading_event;

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
