#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// The Bed Offer Denominator Code Field Indicates The Position Of The Floating Decimal Point Within The Best Offer Price Field
struct BestOfferDenominatorCode {

    static constexpr const char* name = "Best Offer Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr BestOfferDenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestOfferDenominatorCode(const char value)
     : value{ value } {}

    // get value of BestOfferDenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
