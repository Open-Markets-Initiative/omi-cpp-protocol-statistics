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

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Nasdaq will send out this message only if Nasdaq Operations changes the status of a market participant firm in an issue
struct MarketParticipantPositionMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Mpid Mpid;
    itch::Stock Stock;
    itch::PrimaryMarketMaker PrimaryMarketMaker;
    itch::MarketMakerMode MarketMakerMode;
    itch::MarketParticipantState MarketParticipantState;

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
