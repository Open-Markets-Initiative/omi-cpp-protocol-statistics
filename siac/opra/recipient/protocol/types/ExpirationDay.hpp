#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Contains Hex 0 X 01 To 0 X 1f Decimal 1 To 31 Indicating The Day Of The Month The Series Expires
struct ExpirationDay {

    static constexpr const char* name = "Expiration Day";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr ExpirationDay()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ExpirationDay(const std::uint8_t value)
     : value{ value } {}

    // get value of ExpirationDay field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
