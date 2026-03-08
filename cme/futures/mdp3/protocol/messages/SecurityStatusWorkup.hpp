#pragma once

#include "../types/TransactTime.hpp"
#include "../types/MdEntryPxOptionalEx.hpp"
#include "../types/SecurityId.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/TradeDate.hpp"
#include "../types/TradeLinkId.hpp"
#include "../types/WorkupTradingStatus.hpp"
#include "../types/HaltReason.hpp"
#include "../types/SecurityTradingEvent.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// SecurityStatusWorkup
struct SecurityStatusWorkup {

    sbe::TransactTime TransactTime;
    sbe::MdEntryPxOptionalEx MdEntryPxOptionalEx;
    sbe::SecurityId SecurityId;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::TradeDate TradeDate;
    sbe::TradeLinkId TradeLinkId;
    sbe::WorkupTradingStatus WorkupTradingStatus;
    sbe::HaltReason HaltReason;
    sbe::SecurityTradingEvent SecurityTradingEvent;

    // parse method
    static SecurityStatusWorkup* parse(std::byte* buffer) {
        return reinterpret_cast<SecurityStatusWorkup*>(buffer);
    }

    // parse method const
    static const SecurityStatusWorkup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SecurityStatusWorkup*>(buffer);
    }
};

#pragma pack(pop)
}
