#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// The Underlying Price Denominator Code Field Indicates The Position Of The Floating Decimal Point Within The Underlying Price Field
struct UnderlyingPriceDenominatorCode {

    static constexpr const char* name = "Underlying Price Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr UnderlyingPriceDenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingPriceDenominatorCode(const char value)
     : value{ value } {}

    // get value of UnderlyingPriceDenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
