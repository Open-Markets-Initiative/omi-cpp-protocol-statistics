#pragma once

#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/TotNumReportsOptional.hpp"
#include "../types/SecurityUpdateAction.hpp"
#include "../types/LastUpdateTime.hpp"
#include "../types/MdSecurityTradingStatus.hpp"
#include "../types/ApplId.hpp"
#include "../types/MarketSegmentId.hpp"
#include "../types/UnderlyingProductOptional.hpp"
#include "../types/SecurityExchange.hpp"
#include "../types/SecurityGroup.hpp"
#include "../types/Asset.hpp"
#include "../types/Symbol.hpp"
#include "../types/SecurityId.hpp"
#include "../types/SecurityType.hpp"
#include "../types/CfiCode.hpp"
#include "../structs/MaturityMonthYear.hpp"
#include "../types/Currency.hpp"
#include "../types/SecuritySubType.hpp"
#include "../types/UserDefinedInstrument.hpp"
#include "../types/MatchAlgorithm.hpp"
#include "../types/MinTradeVol.hpp"
#include "../types/MaxTradeVol.hpp"
#include "../types/MinPriceIncrementOptional.hpp"
#include "../types/DisplayFactor.hpp"
#include "../types/PriceDisplayFormat.hpp"
#include "../types/PriceRatio.hpp"
#include "../types/TickRule.hpp"
#include "../types/UnitOfMeasure.hpp"
#include "../types/TradingReferencePrice.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/OpenInterestQty.hpp"
#include "../types/ClearedVolume.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/MainFraction.hpp"
#include "../types/SubFraction.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/PriceQuoteMethod.hpp"
#include "../types/RiskSet.hpp"
#include "../types/MarketSet.hpp"
#include "../types/InstrumentGuid.hpp"
#include "../types/FinancialInstrumentFullName.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDInstrumentDefinitionSpread
struct MdInstrumentDefinitionSpread {

    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::TotNumReportsOptional TotNumReportsOptional;
    sbe::SecurityUpdateAction SecurityUpdateAction;
    sbe::LastUpdateTime LastUpdateTime;
    sbe::MdSecurityTradingStatus MdSecurityTradingStatus;
    sbe::ApplId ApplId;
    sbe::MarketSegmentId MarketSegmentId;
    sbe::UnderlyingProductOptional UnderlyingProductOptional;
    sbe::SecurityExchange SecurityExchange;
    sbe::SecurityGroup SecurityGroup;
    sbe::Asset Asset;
    sbe::Symbol Symbol;
    sbe::SecurityId SecurityId;
    sbe::SecurityType SecurityType;
    sbe::CfiCode CfiCode;
    sbe::MaturityMonthYear MaturityMonthYear;
    sbe::Currency Currency;
    sbe::SecuritySubType SecuritySubType;
    sbe::UserDefinedInstrument UserDefinedInstrument;
    sbe::MatchAlgorithm MatchAlgorithm;
    sbe::MinTradeVol MinTradeVol;
    sbe::MaxTradeVol MaxTradeVol;
    sbe::MinPriceIncrementOptional MinPriceIncrementOptional;
    sbe::DisplayFactor DisplayFactor;
    sbe::PriceDisplayFormat PriceDisplayFormat;
    sbe::PriceRatio PriceRatio;
    sbe::TickRule TickRule;
    sbe::UnitOfMeasure UnitOfMeasure;
    sbe::TradingReferencePrice TradingReferencePrice;
    sbe::SettlPriceType SettlPriceType;
    sbe::OpenInterestQty OpenInterestQty;
    sbe::ClearedVolume ClearedVolume;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;
    sbe::MainFraction MainFraction;
    sbe::SubFraction SubFraction;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::PriceQuoteMethod PriceQuoteMethod;
    sbe::RiskSet RiskSet;
    sbe::MarketSet MarketSet;
    sbe::InstrumentGuid InstrumentGuid;
    sbe::FinancialInstrumentFullName FinancialInstrumentFullName;

    // parse method
    static MdInstrumentDefinitionSpread* parse(std::byte* buffer) {
        return reinterpret_cast<MdInstrumentDefinitionSpread*>(buffer);
    }

    // parse method const
    static const MdInstrumentDefinitionSpread* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdInstrumentDefinitionSpread*>(buffer);
    }
};

#pragma pack(pop)
}
