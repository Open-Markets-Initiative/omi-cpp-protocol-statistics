#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/OrderReferenceNumber.hpp"
#include "../types/BuySellIndicator.hpp"
#include "../types/Shares.hpp"
#include "../types/Stock.hpp"
#include "../types/Price.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// This message will be generated for unattributed orders accepted by the Nasdaq system
struct AddOrderNoMpidAttributionMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::OrderReferenceNumber OrderReferenceNumber;
    itch::BuySellIndicator BuySellIndicator;
    itch::Shares Shares;
    itch::Stock Stock;
    itch::Price Price;

    // parse method
    static AddOrderNoMpidAttributionMessage* parse(std::byte* buffer) {
        return reinterpret_cast<AddOrderNoMpidAttributionMessage*>(buffer);
    }

    // parse method const
    static const AddOrderNoMpidAttributionMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const AddOrderNoMpidAttributionMessage*>(buffer);
    }
};

#pragma pack(pop)
}
