#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// The Best Bid Size Identifies The Number Of Contracts Being Bought For An Option At The Best Bid Price
struct BestBidSize {

    static constexpr const char* name = "Best Bid Size";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr BestBidSize()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestBidSize(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of BestBidSize field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
