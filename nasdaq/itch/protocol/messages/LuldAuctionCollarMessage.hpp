#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/AuctionCollarReferencePrice.hpp"
#include "../types/UpperAuctionCollarPrice.hpp"
#include "../types/LowerAuctionCollarPrice.hpp"
#include "../types/AuctionCollarExtension.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Indicates the auction collar thresholds within which a paused security can reopen following a LULD trading pause
struct LuldAuctionCollarMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Stock Stock;
    itch::AuctionCollarReferencePrice AuctionCollarReferencePrice;
    itch::UpperAuctionCollarPrice UpperAuctionCollarPrice;
    itch::LowerAuctionCollarPrice LowerAuctionCollarPrice;
    itch::AuctionCollarExtension AuctionCollarExtension;

    // parse method
    static LuldAuctionCollarMessage* parse(std::byte* buffer) {
        return reinterpret_cast<LuldAuctionCollarMessage*>(buffer);
    }

    // parse method const
    static const LuldAuctionCollarMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const LuldAuctionCollarMessage*>(buffer);
    }
};

#pragma pack(pop)
}
