#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// CollateralMarketValue
struct CollateralMarketValue {

    sbe::TransactTime TransactTime;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding2 Padding2;

    // parse method
    static CollateralMarketValue* parse(std::byte* buffer) {
        return reinterpret_cast<CollateralMarketValue*>(buffer);
    }

    // parse method const
    static const CollateralMarketValue* parse(const std::byte* buffer) {
        return reinterpret_cast<const CollateralMarketValue*>(buffer);
    }
};

#pragma pack(pop)
}
