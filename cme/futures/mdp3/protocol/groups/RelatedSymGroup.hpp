#pragma once

#include "../types/Symbol.hpp"
#include "../types/SecurityId.hpp"
#include "../types/OrderQty.hpp"
#include "../types/QuoteType.hpp"
#include "../types/SideOptional.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct RelatedSymGroup {

    sbe::Symbol Symbol;
    sbe::SecurityId SecurityId;
    sbe::OrderQty OrderQty;
    sbe::QuoteType QuoteType;
    sbe::SideOptional SideOptional;
    sbe::Padding2 Padding2;

    // parse method
    static RelatedSymGroup* parse(std::byte* buffer) {
        return reinterpret_cast<RelatedSymGroup*>(buffer);
    }

    // parse method const
    static const RelatedSymGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const RelatedSymGroup*>(buffer);
    }
};

#pragma pack(pop)
}
