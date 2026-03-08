#pragma once

#include "../types/Year.hpp"
#include "../types/Month.hpp"
#include "../types/Day.hpp"
#include "../types/Week.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct MaturityMonthYear {

    sbe::Year Year;
    sbe::Month Month;
    sbe::Day Day;
    sbe::Week Week;

    // parse method
    static MaturityMonthYear* parse(std::byte* buffer) {
        return reinterpret_cast<MaturityMonthYear*>(buffer);
    }

    // parse method const
    static const MaturityMonthYear* parse(const std::byte* buffer) {
        return reinterpret_cast<const MaturityMonthYear*>(buffer);
    }
};

#pragma pack(pop)
}
