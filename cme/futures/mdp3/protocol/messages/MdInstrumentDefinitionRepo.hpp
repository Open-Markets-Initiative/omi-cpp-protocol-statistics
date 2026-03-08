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
#include "../types/MatchAlgorithm.hpp"
#include "../types/MinTradeVol.hpp"
#include "../types/MaxTradeVol.hpp"
#include "../types/MinPriceIncrement.hpp"
#include "../types/DisplayFactor.hpp"
#include "../types/UnitOfMeasure.hpp"
#include "../types/UnitOfMeasureQty.hpp"
#include "../types/TradingReferencePrice.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/FinancialInstrumentFullName.hpp"
#include "../types/PartyRoleClearingOrg.hpp"
#include "../types/StartDate.hpp"
#include "../types/EndDate.hpp"
#include "../types/TerminationType.hpp"
#include "../types/RepoSubType.hpp"
#include "../types/MoneyOrPar.hpp"
#include "../types/MaxNoOfSubstitutions.hpp"
#include "../types/PriceQuoteMethod.hpp"
#include "../types/UserDefinedInstrument.hpp"
#include "../types/RiskSet.hpp"
#include "../types/MarketSet.hpp"
#include "../types/InstrumentGuid.hpp"
#include "../types/TermCode.hpp"
#include "../types/BrokenDateTermType.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDInstrumentDefinitionRepo
struct MdInstrumentDefinitionRepo {

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
    sbe::MatchAlgorithm MatchAlgorithm;
    sbe::MinTradeVol MinTradeVol;
    sbe::MaxTradeVol MaxTradeVol;
    sbe::MinPriceIncrement MinPriceIncrement;
    sbe::DisplayFactor DisplayFactor;
    sbe::UnitOfMeasure UnitOfMeasure;
    sbe::UnitOfMeasureQty UnitOfMeasureQty;
    sbe::TradingReferencePrice TradingReferencePrice;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;
    sbe::FinancialInstrumentFullName FinancialInstrumentFullName;
    sbe::PartyRoleClearingOrg PartyRoleClearingOrg;
    sbe::StartDate StartDate;
    sbe::EndDate EndDate;
    sbe::TerminationType TerminationType;
    sbe::RepoSubType RepoSubType;
    sbe::MoneyOrPar MoneyOrPar;
    sbe::MaxNoOfSubstitutions MaxNoOfSubstitutions;
    sbe::PriceQuoteMethod PriceQuoteMethod;
    sbe::UserDefinedInstrument UserDefinedInstrument;
    sbe::RiskSet RiskSet;
    sbe::MarketSet MarketSet;
    sbe::InstrumentGuid InstrumentGuid;
    sbe::TermCode TermCode;
    sbe::BrokenDateTermType BrokenDateTermType;

    // parse method
    static MdInstrumentDefinitionRepo* parse(std::byte* buffer) {
        return reinterpret_cast<MdInstrumentDefinitionRepo*>(buffer);
    }

    // parse method const
    static const MdInstrumentDefinitionRepo* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdInstrumentDefinitionRepo*>(buffer);
    }
};

#pragma pack(pop)
}
