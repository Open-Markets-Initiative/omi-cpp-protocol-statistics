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
#include "../structs/MaturityMonthYear.hpp"
#include "../types/Currency.hpp"
#include "../types/SettlCurrency.hpp"
#include "../types/MatchAlgorithm.hpp"
#include "../types/MinTradeVol.hpp"
#include "../types/MaxTradeVol.hpp"
#include "../types/MinPriceIncrement.hpp"
#include "../types/DisplayFactor.hpp"
#include "../types/MainFraction.hpp"
#include "../types/SubFraction.hpp"
#include "../types/PriceDisplayFormat.hpp"
#include "../types/UnitOfMeasure.hpp"
#include "../types/UnitOfMeasureQty.hpp"
#include "../types/TradingReferencePrice.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/OpenInterestQty.hpp"
#include "../types/ClearedVolume.hpp"
#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/DecayQuantity.hpp"
#include "../types/DecayStartDate.hpp"
#include "../types/OriginalContractSize.hpp"
#include "../types/ContractMultiplier.hpp"
#include "../types/ContractMultiplierUnit.hpp"
#include "../types/FlowScheduleType.hpp"
#include "../types/MinPriceIncrementAmount.hpp"
#include "../types/UserDefinedInstrument.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/InstrumentGuid.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// MDInstrumentDefinitionFuture
struct MdInstrumentDefinitionFuture {

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
    sbe::MaturityMonthYear MaturityMonthYear;
    sbe::Currency Currency;
    sbe::SettlCurrency SettlCurrency;
    sbe::MatchAlgorithm MatchAlgorithm;
    sbe::MinTradeVol MinTradeVol;
    sbe::MaxTradeVol MaxTradeVol;
    sbe::MinPriceIncrement MinPriceIncrement;
    sbe::DisplayFactor DisplayFactor;
    sbe::MainFraction MainFraction;
    sbe::SubFraction SubFraction;
    sbe::PriceDisplayFormat PriceDisplayFormat;
    sbe::UnitOfMeasure UnitOfMeasure;
    sbe::UnitOfMeasureQty UnitOfMeasureQty;
    sbe::TradingReferencePrice TradingReferencePrice;
    sbe::SettlPriceType SettlPriceType;
    sbe::OpenInterestQty OpenInterestQty;
    sbe::ClearedVolume ClearedVolume;
    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;
    sbe::DecayQuantity DecayQuantity;
    sbe::DecayStartDate DecayStartDate;
    sbe::OriginalContractSize OriginalContractSize;
    sbe::ContractMultiplier ContractMultiplier;
    sbe::ContractMultiplierUnit ContractMultiplierUnit;
    sbe::FlowScheduleType FlowScheduleType;
    sbe::MinPriceIncrementAmount MinPriceIncrementAmount;
    sbe::UserDefinedInstrument UserDefinedInstrument;
    sbe::TradingReferenceDate TradingReferenceDate;
    sbe::InstrumentGuid InstrumentGuid;

    // parse method
    static MdInstrumentDefinitionFuture* parse(std::byte* buffer) {
        return reinterpret_cast<MdInstrumentDefinitionFuture*>(buffer);
    }

    // parse method const
    static const MdInstrumentDefinitionFuture* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdInstrumentDefinitionFuture*>(buffer);
    }
};

#pragma pack(pop)
}
