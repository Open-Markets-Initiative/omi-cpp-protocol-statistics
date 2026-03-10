#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Price At Which A Buyer Is Willing To Buy An Option
struct BidPriceShort {

    static constexpr const char* name = "Bid Price Short";
    static constexpr std::size_t size = 2;
    using type = std::int16_t;

    // default constructor
    constexpr BidPriceShort()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BidPriceShort(const std::int16_t value)
     : value{ std::byteswap(value) } {}

    // get value of BidPriceShort field
    [[nodiscard]] std::int16_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int16_t value;
};
}
