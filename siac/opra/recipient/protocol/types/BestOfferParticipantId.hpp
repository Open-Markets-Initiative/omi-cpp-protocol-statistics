#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Identifies The Participant That Entered The Best Bid
struct BestOfferParticipantId {

    static constexpr const char* name = "Best Offer Participant Id";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr BestOfferParticipantId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestOfferParticipantId(const char value)
     : value{ value } {}

    // get value of BestOfferParticipantId field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
