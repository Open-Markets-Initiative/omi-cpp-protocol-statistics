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
#include "../types/MinPriceIncrementOptional.hpp"
#include "../types/DisplayFactor.hpp"
#include "../types/MainFraction.hpp"
#include "../types/SubFraction.hpp"
#include "../types/PriceDisplayFormat.hpp"
#include "../types/UnitOfMeasure.hpp"
#include "../types/UnitOfMeasureQty.hpp"
#include "../types/TradingReferencePrice.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/MinPriceIncrementAmount.hpp"
#include "../types/IssueDate.hpp"
#include "../types/DatedDate.hpp"
#include "../types/MaturityDate.hpp"
#include "../types/CouponRate.hpp"
#include "../types/ParValue.hpp"
#include "../types/CouponFrequencyUnit.hpp"
#include "../types/CouponFrequencyPeriod.hpp"
#include "../types/CouponDayCount.hpp"
#include "../types/CountryOfIssue.hpp"
#include "../types/Issuer.hpp"
#include "../types/FinancialInstrumentFullName.hpp"
#include "../types/SecurityAltId.hpp"
#include "../types/SecurityAltIdSource.hpp"
#include "../types/PriceQuoteMethod.hpp"
#include "../types/PartyRoleClearingOrg.hpp"
#include "../types/UserDefinedInstrument.hpp"
#include "../types/RiskSet.hpp"
#include "../types/MarketSet.hpp"
#include "../types/InstrumentGuid.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDInstrumentDefinitionFixedIncome
struct MdInstrumentDefinitionFixedIncome {

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
    sbe::MinPriceIncrementOptional MinPriceIncrementOptional;
    sbe::DisplayFactor DisplayFactor;
    sbe::MainFraction MainFraction;
    sbe::SubFraction SubFraction;
    sbe::PriceDisplayFormat PriceDisplayFormat;
    sbe::UnitOfMeasure UnitOfMeasure;
    sbe::UnitOfMeasureQty UnitOfMeasureQty;
    sbe::TradingReferencePrice TradingReferencePrice;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;
    sbe::MinPriceIncrementAmount MinPriceIncrementAmount;
    sbe::IssueDate IssueDate;
    sbe::DatedDate DatedDate;
    sbe::MaturityDate MaturityDate;
    sbe::CouponRate CouponRate;
    sbe::ParValue ParValue;
    sbe::CouponFrequencyUnit CouponFrequencyUnit;
    sbe::CouponFrequencyPeriod CouponFrequencyPeriod;
    sbe::CouponDayCount CouponDayCount;
    sbe::CountryOfIssue CountryOfIssue;
    sbe::Issuer Issuer;
    sbe::FinancialInstrumentFullName FinancialInstrumentFullName;
    sbe::SecurityAltId SecurityAltId;
    sbe::SecurityAltIdSource SecurityAltIdSource;
    sbe::PriceQuoteMethod PriceQuoteMethod;
    sbe::PartyRoleClearingOrg PartyRoleClearingOrg;
    sbe::UserDefinedInstrument UserDefinedInstrument;
    sbe::RiskSet RiskSet;
    sbe::MarketSet MarketSet;
    sbe::InstrumentGuid InstrumentGuid;

    // parse method
    static MdInstrumentDefinitionFixedIncome* parse(std::byte* buffer) {
        return reinterpret_cast<MdInstrumentDefinitionFixedIncome*>(buffer);
    }

    // parse method const
    static const MdInstrumentDefinitionFixedIncome* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdInstrumentDefinitionFixedIncome*>(buffer);
    }
};

#pragma pack(pop)
}
