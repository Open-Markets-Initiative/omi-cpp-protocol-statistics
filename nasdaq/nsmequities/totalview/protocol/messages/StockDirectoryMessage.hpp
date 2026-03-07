#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Stock.hpp"
#include "../types/MarketCategory.hpp"
#include "../types/FinancialStatusIndicator.hpp"
#include "../types/RoundLotSize.hpp"
#include "../types/RoundLotsOnly.hpp"
#include "../types/IssueClassification.hpp"
#include "../types/IssueSubType.hpp"
#include "../types/Authenticity.hpp"
#include "../types/ShortSaleThresholdIndicator.hpp"
#include "../types/IpoFlag.hpp"
#include "../types/LuldReferencePriceTier.hpp"
#include "../types/EtpFlag.hpp"
#include "../types/EtpLeverageFactor.hpp"
#include "../types/InverseIndicator.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Market data redistributors should process this message to populate the Financial Status Indicator (required display field) and the Market Category (recommended display field) for NASDAQ-listed issues.
struct StockDirectoryMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Stock Stock;
    itch::MarketCategory MarketCategory;
    itch::FinancialStatusIndicator FinancialStatusIndicator;
    itch::RoundLotSize RoundLotSize;
    itch::RoundLotsOnly RoundLotsOnly;
    itch::IssueClassification IssueClassification;
    itch::IssueSubType IssueSubType;
    itch::Authenticity Authenticity;
    itch::ShortSaleThresholdIndicator ShortSaleThresholdIndicator;
    itch::IpoFlag IpoFlag;
    itch::LuldReferencePriceTier LuldReferencePriceTier;
    itch::EtpFlag EtpFlag;
    itch::EtpLeverageFactor EtpLeverageFactor;
    itch::InverseIndicator InverseIndicator;

    // parse method
    static StockDirectoryMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StockDirectoryMessage*>(buffer);
    }

    // parse method const
    static const StockDirectoryMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StockDirectoryMessage*>(buffer);
    }
};

#pragma pack(pop)
}
