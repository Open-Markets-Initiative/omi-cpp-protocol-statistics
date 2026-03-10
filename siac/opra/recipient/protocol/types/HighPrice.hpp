#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Highest Price Paid For An Option During The Trading Day
struct HighPrice {

    static constexpr const char* name = "High Price";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr HighPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit HighPrice(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of HighPrice field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
