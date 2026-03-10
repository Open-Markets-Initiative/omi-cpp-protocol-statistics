#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Price Of An Option Contract Determined In The Competitive Marketplace Which The Buyer Of The Option Pays To The Option Writer For The Rights Conveyed By The Option Contract
struct PremiumPrice {

    static constexpr const char* name = "Premium Price";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr PremiumPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PremiumPrice(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of PremiumPrice field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
