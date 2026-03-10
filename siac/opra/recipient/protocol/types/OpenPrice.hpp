#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The First Price Paid For An Option During The Trading Day
struct OpenPrice {

    static constexpr const char* name = "Open Price";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr OpenPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OpenPrice(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of OpenPrice field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
