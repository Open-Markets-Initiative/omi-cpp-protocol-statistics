#pragma once

#include "../types/RelatedSecurityId.hpp"
#include "../types/RelatedSymbol.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct OptionRelatedInstrumentsGroup {

    sbe::RelatedSecurityId RelatedSecurityId;
    sbe::RelatedSymbol RelatedSymbol;

    // parse method
    static OptionRelatedInstrumentsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<OptionRelatedInstrumentsGroup*>(buffer);
    }

    // parse method const
    static const OptionRelatedInstrumentsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const OptionRelatedInstrumentsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
