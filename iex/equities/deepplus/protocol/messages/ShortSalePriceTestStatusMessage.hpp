#pragma once

#include "../types/ShortSalePriceTestStatus.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/Detail.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// The Short Sale Price Test Message is used to indicate when a short sale price test restriction is in effect for a security.
struct ShortSalePriceTestStatusMessage {

    iextp::ShortSalePriceTestStatus ShortSalePriceTestStatus;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;
    iextp::Detail Detail;

    // parse method
    static ShortSalePriceTestStatusMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ShortSalePriceTestStatusMessage*>(buffer);
    }

    // parse method const
    static const ShortSalePriceTestStatusMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ShortSalePriceTestStatusMessage*>(buffer);
    }
};

#pragma pack(pop)
}
