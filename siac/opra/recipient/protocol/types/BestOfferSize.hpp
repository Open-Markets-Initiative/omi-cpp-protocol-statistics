#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// The Best Offer Size Identifies The Number Of Contracts Being Bought For An Option At The Best Offer Price
struct BestOfferSize {

    static constexpr const char* name = "Best Offer Size";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr BestOfferSize()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestOfferSize(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of BestOfferSize field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
