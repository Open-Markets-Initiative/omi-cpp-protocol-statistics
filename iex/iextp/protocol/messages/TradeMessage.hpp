#pragma once

#include "../bitfields/SaleConditionFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"
#include "../types/TradeId.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// A non-displayed order on the book that executed against another non-displayed order on the book
struct TradeMessage {

    iextp::SaleConditionFlags SaleConditionFlags;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;
    iextp::Size Size;
    iextp::Price Price;
    iextp::TradeId TradeId;

    // parse method
    static TradeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<TradeMessage*>(buffer);
    }

    // parse method const
    static const TradeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const TradeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
