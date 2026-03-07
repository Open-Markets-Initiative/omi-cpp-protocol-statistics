#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/IpoQuotationReleaseTime.hpp"
#include "../types/IpoQuotationReleaseQualifier.hpp"
#include "../types/IpoPrice.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Indicates the anticipated IPO quotation release time of a security.
struct IpoQuotingPeriodUpdate {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Stock Stock;
    itch::IpoQuotationReleaseTime IpoQuotationReleaseTime;
    itch::IpoQuotationReleaseQualifier IpoQuotationReleaseQualifier;
    itch::IpoPrice IpoPrice;

    // parse method
    static IpoQuotingPeriodUpdate* parse(std::byte* buffer) {
        return reinterpret_cast<IpoQuotingPeriodUpdate*>(buffer);
    }

    // parse method const
    static const IpoQuotingPeriodUpdate* parse(const std::byte* buffer) {
        return reinterpret_cast<const IpoQuotingPeriodUpdate*>(buffer);
    }
};

#pragma pack(pop)
}
