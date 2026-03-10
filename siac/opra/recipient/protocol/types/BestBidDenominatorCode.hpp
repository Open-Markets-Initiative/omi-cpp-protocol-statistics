#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// The Bed Bid Denominator Code Field Indicates The Position Of The Floating Decimal Point Within The Best Bid Price Field
struct BestBidDenominatorCode {

    static constexpr const char* name = "Best Bid Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr BestBidDenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestBidDenominatorCode(const char value)
     : value{ value } {}

    // get value of BestBidDenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
