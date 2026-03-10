#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/TradingState.hpp"
#include "../types/Reserved.hpp"
#include "../types/ReasonCode.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Nasdaq uses this administrative message to indicate the current trading status of a security to the trading community
struct StockTradingActionMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    Stock stock;
    TradingState trading_state;
    Reserved reserved;
    ReasonCode reason_code;

    // parse method
    static StockTradingActionMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StockTradingActionMessage*>(buffer);
    }

    // parse method const
    static const StockTradingActionMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StockTradingActionMessage*>(buffer);
    }
};

#pragma pack(pop)
}
