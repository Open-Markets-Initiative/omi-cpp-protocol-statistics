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
#include "../types/PutOrCall.hpp"
#include "../structs/MaturityMonthYear.hpp"
#include "../types/Currency.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/StrikeCurrency.hpp"
#include "../types/SettlCurrency.hpp"
#include "../types/MinCabPrice.hpp"
#include "../types/MatchAlgorithm.hpp"
#include "../types/MinTradeVol.hpp"
#include "../types/MaxTradeVol.hpp"
#include "../types/MinPriceIncrementOptional.hpp"
#include "../types/MinPriceIncrementAmount.hpp"
#include "../types/DisplayFactor.hpp"
#include "../types/TickRule.hpp"
#include "../types/MainFraction.hpp"
#include "../types/SubFraction.hpp"
#include "../types/PriceDisplayFormat.hpp"
#include "../types/UnitOfMeasure.hpp"
#include "../types/UnitOfMeasureQty.hpp"
#include "../types/TradingReferencePrice.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/ClearedVolume.hpp"
#include "../types/OpenInterestQty.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/UserDefinedInstrument.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/InstrumentGuid.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDInstrumentDefinitionOption
struct MdInstrumentDefinitionOption {

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
    sbe::PutOrCall PutOrCall;
    sbe::MaturityMonthYear MaturityMonthYear;
    sbe::Currency Currency;
    sbe::StrikePrice StrikePrice;
    sbe::StrikeCurrency StrikeCurrency;
    sbe::SettlCurrency SettlCurrency;
    sbe::MinCabPrice MinCabPrice;
    sbe::MatchAlgorithm MatchAlgorithm;
    sbe::MinTradeVol MinTradeVol;
    sbe::MaxTradeVol MaxTradeVol;
    sbe::MinPriceIncrementOptional MinPriceIncrementOptional;
    sbe::MinPriceIncrementAmount MinPriceIncrementAmount;
    sbe::DisplayFactor DisplayFactor;
    sbe::TickRule TickRule;
    sbe::MainFraction MainFraction;
    sbe::SubFraction SubFraction;
    sbe::PriceDisplayFormat PriceDisplayFormat;
    sbe::UnitOfMeasure UnitOfMeasure;
    sbe::UnitOfMeasureQty UnitOfMeasureQty;
    sbe::TradingReferencePrice TradingReferencePrice;
    sbe::SettlPriceType SettlPriceType;
    sbe::ClearedVolume ClearedVolume;
    sbe::OpenInterestQty OpenInterestQty;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::UserDefinedInstrument UserDefinedInstrument;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::InstrumentGuid InstrumentGuid;

    // parse method
    static MdInstrumentDefinitionOption* parse(std::byte* buffer) {
        return reinterpret_cast<MdInstrumentDefinitionOption*>(buffer);
    }

    // parse method const
    static const MdInstrumentDefinitionOption* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdInstrumentDefinitionOption*>(buffer);
    }
};

#pragma pack(pop)
}
