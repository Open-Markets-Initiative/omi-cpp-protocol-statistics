#pragma once

#include "../types/ParticipantId.hpp"
#include "../types/DenominatorCode.hpp"
#include "../types/Price.hpp"
#include "../types/Size.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct BestOfferAppendage {

    ParticipantId participant_id;
    DenominatorCode denominator_code;
    Price price;
    Size size;

    // parse method
    static BestOfferAppendage* parse(std::byte* buffer) {
        return reinterpret_cast<BestOfferAppendage*>(buffer);
    }

    // parse method const
    static const BestOfferAppendage* parse(const std::byte* buffer) {
        return reinterpret_cast<const BestOfferAppendage*>(buffer);
    }
};

#pragma pack(pop)
}
