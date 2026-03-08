#pragma once

#include "../types/TradeDate.hpp"
#include "../types/SettlDate.hpp"
#include "../types/MaturityDate.hpp"
#include "../types/SecurityAltId.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct TradingSessionsGroup {

    sbe::TradeDate TradeDate;
    sbe::SettlDate SettlDate;
    sbe::MaturityDate MaturityDate;
    sbe::SecurityAltId SecurityAltId;

    // parse method
    static TradingSessionsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<TradingSessionsGroup*>(buffer);
    }

    // parse method const
    static const TradingSessionsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const TradingSessionsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
