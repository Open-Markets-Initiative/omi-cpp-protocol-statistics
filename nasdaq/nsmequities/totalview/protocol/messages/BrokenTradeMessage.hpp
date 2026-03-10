#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/MatchNumber.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// The Broken Trade Message is sent whenever an execution on Nasdaq is broken
struct BrokenTradeMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    MatchNumber match_number;

    // parse method
    static BrokenTradeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<BrokenTradeMessage*>(buffer);
    }

    // parse method const
    static const BrokenTradeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BrokenTradeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
