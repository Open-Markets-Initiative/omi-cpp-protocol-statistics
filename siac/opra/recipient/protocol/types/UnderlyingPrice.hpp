#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Price Of The Underlying Security
struct UnderlyingPrice {

    static constexpr const char* name = "Underlying Price";
    static constexpr std::size_t size = 8;
    using type = std::int64_t;

    // default constructor
    constexpr UnderlyingPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingPrice(const std::int64_t value)
     : value{ std::byteswap(value) } {}

    // get value of UnderlyingPrice field
    [[nodiscard]] std::int64_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int64_t value;
};
}
