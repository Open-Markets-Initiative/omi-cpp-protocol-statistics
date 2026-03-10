#pragma once

#include "../types/TradingStatus.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/Reason.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

#pragma pack(push, 1)

// The Trading Status Message is used to indicate the current trading status of a security.
struct TradingStatusMessage {

    TradingStatus trading_status;
    Timestamp timestamp;
    Symbol symbol;
    Reason reason;

    // parse method
    static TradingStatusMessage* parse(std::byte* buffer) {
        return reinterpret_cast<TradingStatusMessage*>(buffer);
    }

    // parse method const
    static const TradingStatusMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const TradingStatusMessage*>(buffer);
    }
};

#pragma pack(pop)
}
