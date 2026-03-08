#pragma once

#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshLimitsBandingGroup {

    sbe::HighLimitPrice HighLimitPrice;
    sbe::LowLimitPrice LowLimitPrice;
    sbe::MaxPriceVariation MaxPriceVariation;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;

    // parse method
    static IncrementalRefreshLimitsBandingGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshLimitsBandingGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshLimitsBandingGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshLimitsBandingGroup*>(buffer);
    }
};

#pragma pack(pop)
}
