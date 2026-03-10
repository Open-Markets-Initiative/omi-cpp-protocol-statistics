#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// The Bid Size Identifies The Number Of Contracts Being Bought For An Option At The Bid Price
struct BidSize {

    static constexpr const char* name = "Bid Size";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr BidSize()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BidSize(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of BidSize field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
