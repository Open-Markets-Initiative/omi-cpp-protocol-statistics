#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// The Bid Size Identifies The Number Of Contracts Being Bought For An Option At The Bid Price
struct DenominatorCode {

    static constexpr const char* name = "Denominator Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr DenominatorCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DenominatorCode(const char value)
     : value{ value } {}

    // get value of DenominatorCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
