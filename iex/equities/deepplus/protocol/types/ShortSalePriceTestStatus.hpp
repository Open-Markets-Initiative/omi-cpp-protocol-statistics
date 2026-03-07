#pragma once

#include <cstddef>

namespace iex::equities::deepplus::iextp::v1_0_1 {

// Reg. SHO short sale price test restriction status
struct ShortSalePriceTestStatus {

    static constexpr const char* name = "Short Sale Price Test Status";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ShortSalePriceTestStatus()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ShortSalePriceTestStatus(const char value)
     : value{ value } {}

    // get value of ShortSalePriceTestStatus field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
