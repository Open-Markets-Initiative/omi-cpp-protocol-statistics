#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Best Price At Which A Buyer Is Willing To Buy An Option
struct BestBidPrice {

    static constexpr const char* name = "Best Bid Price";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr BestBidPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BestBidPrice(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of BestBidPrice field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
