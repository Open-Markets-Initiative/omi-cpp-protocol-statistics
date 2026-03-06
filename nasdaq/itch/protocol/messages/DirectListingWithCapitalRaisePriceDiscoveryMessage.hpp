#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/OpenEligibilityStatus.hpp"
#include "../types/MinimumAllowablePrice.hpp"
#include "../types/MaximumAllowablePrice.hpp"
#include "../types/NearExecutionPrice.hpp"
#include "../types/NearExecutionTime.hpp"
#include "../types/LowerPriceRangeCollar.hpp"
#include "../types/UpperPriceRangeCollar.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// This message is disseminated only for Direct Listing with Capital Raise (DLCR) securities
struct DirectListingWithCapitalRaisePriceDiscoveryMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Stock Stock;
    itch::OpenEligibilityStatus OpenEligibilityStatus;
    itch::MinimumAllowablePrice MinimumAllowablePrice;
    itch::MaximumAllowablePrice MaximumAllowablePrice;
    itch::NearExecutionPrice NearExecutionPrice;
    itch::NearExecutionTime NearExecutionTime;
    itch::LowerPriceRangeCollar LowerPriceRangeCollar;
    itch::UpperPriceRangeCollar UpperPriceRangeCollar;

    // parse method
    static DirectListingWithCapitalRaisePriceDiscoveryMessage* parse(std::byte* buffer) {
        return reinterpret_cast<DirectListingWithCapitalRaisePriceDiscoveryMessage*>(buffer);
    }

    // parse method const
    static const DirectListingWithCapitalRaisePriceDiscoveryMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const DirectListingWithCapitalRaisePriceDiscoveryMessage*>(buffer);
    }
};

#pragma pack(pop)
}
