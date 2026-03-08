#pragma once

#include "../types/BrokenDateGuid.hpp"
#include "../types/BrokenDateSecurityId.hpp"
#include "../types/BrokenDateStart.hpp"
#include "../types/BrokenDateEnd.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct BrokenDatesGroup {

    sbe::BrokenDateGuid BrokenDateGuid;
    sbe::BrokenDateSecurityId BrokenDateSecurityId;
    sbe::BrokenDateStart BrokenDateStart;
    sbe::BrokenDateEnd BrokenDateEnd;

    // parse method
    static BrokenDatesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<BrokenDatesGroup*>(buffer);
    }

    // parse method const
    static const BrokenDatesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const BrokenDatesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
