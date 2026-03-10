#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Mpid.hpp"
#include "../types/Stock.hpp"
#include "../types/PrimaryMarketMaker.hpp"
#include "../types/MarketMakerMode.hpp"
#include "../types/MarketParticipantState.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Nasdaq will send out this message only if Nasdaq Operations changes the status of a market participant firm in an issue
struct MarketParticipantPositionMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    Mpid mpid;
    Stock stock;
    PrimaryMarketMaker primary_market_maker;
    MarketMakerMode market_maker_mode;
    MarketParticipantState market_participant_state;

    // parse method
    static MarketParticipantPositionMessage* parse(std::byte* buffer) {
        return reinterpret_cast<MarketParticipantPositionMessage*>(buffer);
    }

    // parse method const
    static const MarketParticipantPositionMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const MarketParticipantPositionMessage*>(buffer);
    }
};

#pragma pack(pop)
}
