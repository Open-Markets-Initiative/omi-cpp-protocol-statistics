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

#pragma pack(push, 1)

// This message is disseminated only for Direct Listing with Capital Raise (DLCR) securities
struct DirectListingWithCapitalRaisePriceDiscoveryMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    Stock stock;
    OpenEligibilityStatus open_eligibility_status;
    MinimumAllowablePrice minimum_allowable_price;
    MaximumAllowablePrice maximum_allowable_price;
    NearExecutionPrice near_execution_price;
    NearExecutionTime near_execution_time;
    LowerPriceRangeCollar lower_price_range_collar;
    UpperPriceRangeCollar upper_price_range_collar;

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
