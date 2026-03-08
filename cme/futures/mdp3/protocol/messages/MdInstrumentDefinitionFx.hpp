#pragma once

#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/TotNumReportsOptional.hpp"
#include "../types/SecurityUpdateAction.hpp"
#include "../types/LastUpdateTime.hpp"
#include "../types/MdSecurityTradingStatus.hpp"
#include "../types/ApplId.hpp"
#include "../types/MarketSegmentId.hpp"
#include "../types/UnderlyingProduct.hpp"
#include "../types/SecurityExchange.hpp"
#include "../types/SecurityGroup.hpp"
#include "../types/Asset.hpp"
#include "../types/Symbol.hpp"
#include "../types/SecurityId.hpp"
#include "../types/SecurityType.hpp"
#include "../types/CfiCode.hpp"
#include "../types/Currency.hpp"
#include "../types/SettlCurrency.hpp"
#include "../types/PriceQuoteCurrency.hpp"
#include "../types/MatchAlgorithm.hpp"
#include "../types/MinTradeVol.hpp"
#include "../types/MaxTradeVol.hpp"
#include "../types/MinPriceIncrement.hpp"
#include "../types/DisplayFactor.hpp"
#include "../types/PricePrecision.hpp"
#include "../types/UnitOfMeasure.hpp"
#include "../types/UnitOfMeasureQty.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/UserDefinedInstrument.hpp"
#include "../types/FinancialInstrumentFullName.hpp"
#include "../types/FxCurrencySymbol.hpp"
#include "../types/SettlType.hpp"
#include "../types/InterveningDays.hpp"
#include "../types/FxBenchmarkRateFix.hpp"
#include "../types/RateSource.hpp"
#include "../types/FixRateLocalTime.hpp"
#include "../types/FixRateLocalTimeZone.hpp"
#include "../types/MinQuoteLife.hpp"
#include "../types/MaxPriceDiscretionOffset.hpp"
#include "../types/InstrumentGuid.hpp"
#include "../structs/MaturityMonthYear.hpp"
#include "../types/SettlementLocale.hpp"
#include "../types/AltMinPriceIncrement.hpp"
#include "../types/AltMinQuoteLife.hpp"
#include "../types/AltPriceIncrementConstraint.hpp"
#include "../types/MaxBidAskConstraint.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDInstrumentDefinitionFX
struct MdInstrumentDefinitionFx {

    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::TotNumReportsOptional TotNumReportsOptional;
    sbe::SecurityUpdateAction SecurityUpdateAction;
    sbe::LastUpdateTime LastUpdateTime;
    sbe::MdSecurityTradingStatus MdSecurityTradingStatus;
    sbe::ApplId ApplId;
    sbe::MarketSegmentId MarketSegmentId;
    sbe::UnderlyingProduct UnderlyingProduct;
    sbe::SecurityExchange SecurityExchange;
    sbe::SecurityGroup SecurityGroup;
    sbe::Asset Asset;
    sbe::Symbol Symbol;
    sbe::SecurityId SecurityId;
    sbe::SecurityType SecurityType;
    sbe::CfiCode CfiCode;
    sbe::Currency Currency;
    sbe::SettlCurrency SettlCurrency;
    sbe::PriceQuoteCurrency PriceQuoteCurrency;
    sbe::MatchAlgorithm MatchAlgorithm;
    sbe::MinTradeVol MinTradeVol;
    sbe::MaxTradeVol MaxTradeVol;
    sbe::MinPriceIncrement MinPriceIncrement;
    sbe::DisplayFactor DisplayFactor;
    sbe::PricePrecision PricePrecision;
    sbe::UnitOfMeasure UnitOfMeasure;
    sbe::UnitOfMeasureQty UnitOfMeasureQty;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;
    sbe::UserDefinedInstrument UserDefinedInstrument;
    sbe::FinancialInstrumentFullName FinancialInstrumentFullName;
    sbe::FxCurrencySymbol FxCurrencySymbol;
    sbe::SettlType SettlType;
    sbe::InterveningDays InterveningDays;
    sbe::FxBenchmarkRateFix FxBenchmarkRateFix;
    sbe::RateSource RateSource;
    sbe::FixRateLocalTime FixRateLocalTime;
    sbe::FixRateLocalTimeZone FixRateLocalTimeZone;
    sbe::MinQuoteLife MinQuoteLife;
    sbe::MaxPriceDiscretionOffset MaxPriceDiscretionOffset;
    sbe::InstrumentGuid InstrumentGuid;
    sbe::MaturityMonthYear MaturityMonthYear;
    sbe::SettlementLocale SettlementLocale;
    sbe::AltMinPriceIncrement AltMinPriceIncrement;
    sbe::AltMinQuoteLife AltMinQuoteLife;
    sbe::AltPriceIncrementConstraint AltPriceIncrementConstraint;
    sbe::MaxBidAskConstraint MaxBidAskConstraint;

    // parse method
    static MdInstrumentDefinitionFx* parse(std::byte* buffer) {
        return reinterpret_cast<MdInstrumentDefinitionFx*>(buffer);
    }

    // parse method const
    static const MdInstrumentDefinitionFx* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdInstrumentDefinitionFx*>(buffer);
    }
};

#pragma pack(pop)
}
