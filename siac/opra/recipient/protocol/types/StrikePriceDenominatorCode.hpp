#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// The Strike Price Denominator Code Field Indicates The Position Of The Floating Decimal Point Within The Strike Price Field
struct StrikePriceDenominatorCode {

    static constexpr const char* name = "Strike Price Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr StrikePriceDenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StrikePriceDenominatorCode(const char value)
     : value{ value } {}

    // get value of StrikePriceDenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
