#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/CrossShares.hpp"
#include "../types/Stock.hpp"
#include "../types/CrossPrice.hpp"
#include "../types/MatchNumber.hpp"
#include "../types/CrossType.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Cross Trade message indicates that Nasdaq has completed its cross process for a specific security
struct CrossTradeMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::CrossShares CrossShares;
    itch::Stock Stock;
    itch::CrossPrice CrossPrice;
    itch::MatchNumber MatchNumber;
    itch::CrossType CrossType;

    // parse method
    static CrossTradeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<CrossTradeMessage*>(buffer);
    }

    // parse method const
    static const CrossTradeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const CrossTradeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
