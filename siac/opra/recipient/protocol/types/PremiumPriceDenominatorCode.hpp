#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The First Price Paid For An Option During The Trading Day
struct PremiumPriceDenominatorCode {

    static constexpr const char* name = "Premium Price Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr PremiumPriceDenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PremiumPriceDenominatorCode(const char value)
     : value{ value } {}

    // get value of PremiumPriceDenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
