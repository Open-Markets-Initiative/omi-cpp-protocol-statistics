#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Contains Hex 0 X 00 To 0 X 63 Decimal 0 To 99 Represents The Year Starting With Year 2000
struct ExpirationYear {

    static constexpr const char* name = "Expiration Year";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr ExpirationYear()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ExpirationYear(const std::uint8_t value)
     : value{ value } {}

    // get value of ExpirationYear field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
