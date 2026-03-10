#pragma once

#include "../types/LocateCode.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/RegShoAction.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Nasaq processes orders based on the most Reg SHO Restriction status value
struct RegShoShortSalePriceTestRestrictedIndicatorMessage {

    LocateCode locate_code;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    Stock stock;
    RegShoAction reg_sho_action;

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
