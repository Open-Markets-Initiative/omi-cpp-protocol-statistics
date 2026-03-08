#pragma once

#include "../types/LegSecurityId.hpp"
#include "../types/LegSide.hpp"
#include "../types/LegRatioQty.hpp"
#include "../types/LegPrice.hpp"
#include "../types/LegOptionDelta.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct LegsGroup {

    sbe::LegSecurityId LegSecurityId;
    sbe::LegSide LegSide;
    sbe::LegRatioQty LegRatioQty;
    sbe::LegPrice LegPrice;
    sbe::LegOptionDelta LegOptionDelta;

    // parse method
    static LegsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<LegsGroup*>(buffer);
    }

    // parse method const
    static const LegsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const LegsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
