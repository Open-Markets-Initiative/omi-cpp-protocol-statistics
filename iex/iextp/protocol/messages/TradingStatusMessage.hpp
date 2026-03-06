#pragma once

#include "../types/TradingStatus.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/Reason.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// The Trading Status Message is used to indicate the current trading status of a security.
struct TradingStatusMessage {

    iextp::TradingStatus TradingStatus;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;
    iextp::Reason Reason;

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
