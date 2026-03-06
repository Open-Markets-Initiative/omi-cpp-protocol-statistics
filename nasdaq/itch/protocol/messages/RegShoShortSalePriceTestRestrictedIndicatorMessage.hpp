#pragma once

#include "../types/LocateCode.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/RegShoAction.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Nasaq processes orders based on the most Reg SHO Restriction status value
struct RegShoShortSalePriceTestRestrictedIndicatorMessage {

    itch::LocateCode LocateCode;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Stock Stock;
    itch::RegShoAction RegShoAction;

    // parse method
    static RegShoShortSalePriceTestRestrictedIndicatorMessage* parse(std::byte* buffer) {
        return reinterpret_cast<RegShoShortSalePriceTestRestrictedIndicatorMessage*>(buffer);
    }

    // parse method const
    static const RegShoShortSalePriceTestRestrictedIndicatorMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const RegShoShortSalePriceTestRestrictedIndicatorMessage*>(buffer);
    }
};

#pragma pack(pop)
}
