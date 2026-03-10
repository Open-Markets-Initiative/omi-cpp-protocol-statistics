#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Price At Which A Buyer Is Willing To Buy An Option
struct BidPrice {

    static constexpr const char* name = "Bid Price";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr BidPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BidPrice(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of BidPrice field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
