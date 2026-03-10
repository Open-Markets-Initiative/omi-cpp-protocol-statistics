#pragma once

#include "../bitfields/SaleConditionFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"
#include "../types/TradeId.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

#pragma pack(push, 1)

// Trade Break Messages are sent when an execution on IEX is broken on that same trading day
struct TradeBreakMessage {

    SaleConditionFlags sale_condition_flags;
    Timestamp timestamp;
    Symbol symbol;
    Size size;
    Price price;
    TradeId trade_id;

    // parse method
    static TradeBreakMessage* parse(std::byte* buffer) {
        return reinterpret_cast<TradeBreakMessage*>(buffer);
    }

    // parse method const
    static const TradeBreakMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const TradeBreakMessage*>(buffer);
    }
};

#pragma pack(pop)
}
