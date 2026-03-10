#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Identifies The Participant That Entered The Best Bid
struct BestBidParticipantId {

    static constexpr const char* name = "Best Bid Participant Id";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr BestBidParticipantId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestBidParticipantId(const char value)
     : value{ value } {}

    // get value of BestBidParticipantId field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
