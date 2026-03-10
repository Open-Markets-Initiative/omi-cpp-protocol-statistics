#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Stated Price Per Share For Which The Underlying Security May Be Purchased In The Case Of A Call Or Sold In The Case Of A Put By The Option Holder Upon Exercise Of The Option Contract
struct StrikePrice {

    static constexpr const char* name = "Strike Price";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr StrikePrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StrikePrice(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of StrikePrice field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
