#pragma once

#include "../types/UnderlyingSymbol.hpp"
#include "../types/UnderlyingSecurityIdOptional.hpp"
#include "../types/UnderlyingSecurityAltId.hpp"
#include "../types/UnderlyingSecurityAltIdSource.hpp"
#include "../types/UnderlyingFinancialInstrumentFullName.hpp"
#include "../types/UnderlyingSecurityType.hpp"
#include "../types/UnderlyingCountryOfIssue.hpp"
#include "../types/UnderlyingIssuer.hpp"
#include "../types/UnderlyingMaxLifeTime.hpp"
#include "../types/UnderlyingMinDaysToMaturity.hpp"
#include "../types/UnderlyingInstrumentGuidOptional.hpp"
#include "../types/UnderlyingMaturityDate.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct RepoUnderlyingsGroup {

    sbe::UnderlyingSymbol UnderlyingSymbol;
    sbe::UnderlyingSecurityIdOptional UnderlyingSecurityIdOptional;
    sbe::UnderlyingSecurityAltId UnderlyingSecurityAltId;
    sbe::UnderlyingSecurityAltIdSource UnderlyingSecurityAltIdSource;
    sbe::UnderlyingFinancialInstrumentFullName UnderlyingFinancialInstrumentFullName;
    sbe::UnderlyingSecurityType UnderlyingSecurityType;
    sbe::UnderlyingCountryOfIssue UnderlyingCountryOfIssue;
    sbe::UnderlyingIssuer UnderlyingIssuer;
    sbe::UnderlyingMaxLifeTime UnderlyingMaxLifeTime;
    sbe::UnderlyingMinDaysToMaturity UnderlyingMinDaysToMaturity;
    sbe::UnderlyingInstrumentGuidOptional UnderlyingInstrumentGuidOptional;
    sbe::UnderlyingMaturityDate UnderlyingMaturityDate;

    // parse method
    static RepoUnderlyingsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<RepoUnderlyingsGroup*>(buffer);
    }

    // parse method const
    static const RepoUnderlyingsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const RepoUnderlyingsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
