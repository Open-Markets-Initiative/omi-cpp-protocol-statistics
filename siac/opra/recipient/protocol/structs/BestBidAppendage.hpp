#pragma once

#include "../types/ParticipantId.hpp"
#include "../types/DenominatorCode.hpp"
#include "../types/Price.hpp"
#include "../types/Size.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct BestBidAppendage {

    ParticipantId participant_id;
    DenominatorCode denominator_code;
    Price price;
    Size size;

    // parse method
    static BestBidAppendage* parse(std::byte* buffer) {
        return reinterpret_cast<BestBidAppendage*>(buffer);
    }

    // parse method const
    static const BestBidAppendage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BestBidAppendage*>(buffer);
    }
};

#pragma pack(pop)
}
