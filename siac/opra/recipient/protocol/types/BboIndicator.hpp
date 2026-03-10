#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Indicates The Effect The New Quote Has On The Best Bid Andor The Best Offer
struct BboIndicator {

    static constexpr const char* name = "Bbo Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr BboIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BboIndicator(const char value)
     : value{ value } {}

    // get value of BboIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
