#pragma once

#include "../types/MdEntrySizeShort.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/Padding3.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct IncrementalRefreshVolumeGroup {

    sbe::MdEntrySizeShort MdEntrySizeShort;
    sbe::SecurityId SecurityId;
    sbe::RptSeq RptSeq;
    sbe::MdUpdateAction MdUpdateAction;
    sbe::Padding3 Padding3;

    // parse method
    static IncrementalRefreshVolumeGroup* parse(std::byte* buffer) {
        return reinterpret_cast<IncrementalRefreshVolumeGroup*>(buffer);
    }

    // parse method const
    static const IncrementalRefreshVolumeGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const IncrementalRefreshVolumeGroup*>(buffer);
    }
};

#pragma pack(pop)
}
