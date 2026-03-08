#pragma once

#include "../types/UnderlyingSecurityAltId.hpp"
#include "../types/UnderlyingSecurityAltIdSource.hpp"
#include "../types/CollateralMarketPrice.hpp"
#include "../types/DirtyPrice.hpp"
#include "../types/UnderlyingInstrumentGuid.hpp"
#include "../types/MdStreamId.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct CollateralMarketValueGroup {

    sbe::UnderlyingSecurityAltId UnderlyingSecurityAltId;
    sbe::UnderlyingSecurityAltIdSource UnderlyingSecurityAltIdSource;
    sbe::CollateralMarketPrice CollateralMarketPrice;
    sbe::DirtyPrice DirtyPrice;
    sbe::UnderlyingInstrumentGuid UnderlyingInstrumentGuid;
    sbe::MdStreamId MdStreamId;
    sbe::Padding2 Padding2;

    // parse method
    static CollateralMarketValueGroup* parse(std::byte* buffer) {
        return reinterpret_cast<CollateralMarketValueGroup*>(buffer);
    }

    // parse method const
    static const CollateralMarketValueGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const CollateralMarketValueGroup*>(buffer);
    }
};

#pragma pack(pop)
}
