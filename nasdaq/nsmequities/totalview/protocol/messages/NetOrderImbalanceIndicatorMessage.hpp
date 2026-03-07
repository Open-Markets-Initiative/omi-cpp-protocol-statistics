#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/PairedShares.hpp"
#include "../types/ImbalanceShares.hpp"
#include "../types/ImbalanceDirection.hpp"
#include "../types/Stock.hpp"
#include "../types/FarPrice.hpp"
#include "../types/NearPrice.hpp"
#include "../types/CurrentReferencePrice.hpp"
#include "../types/CrossType.hpp"
#include "../types/PriceVariationIndicator.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// NASDAQ disseminates NOII data
struct NetOrderImbalanceIndicatorMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::PairedShares PairedShares;
    itch::ImbalanceShares ImbalanceShares;
    itch::ImbalanceDirection ImbalanceDirection;
    itch::Stock Stock;
    itch::FarPrice FarPrice;
    itch::NearPrice NearPrice;
    itch::CurrentReferencePrice CurrentReferencePrice;
    itch::CrossType CrossType;
    itch::PriceVariationIndicator PriceVariationIndicator;

    // parse method
    static NetOrderImbalanceIndicatorMessage* parse(std::byte* buffer) {
        return reinterpret_cast<NetOrderImbalanceIndicatorMessage*>(buffer);
    }

    // parse method const
    static const NetOrderImbalanceIndicatorMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const NetOrderImbalanceIndicatorMessage*>(buffer);
    }
};

#pragma pack(pop)
}
