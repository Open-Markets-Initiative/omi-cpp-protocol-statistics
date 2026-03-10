#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Stated Price Per Share For Which The Underlying Security May Be Purchased In The Case Of A Call Or Sold In The Case Of A Put By The Option Holder Upon Exercise Of The Option Contract
struct StrikePriceShort {

    static constexpr const char* name = "Strike Price Short";
    static constexpr std::size_t size = 2;
    using type = std::uint16_t;

    // default constructor
    constexpr StrikePriceShort()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StrikePriceShort(const std::uint16_t value)
     : value{ std::byteswap(value) } {}

    // get value of StrikePriceShort field
    [[nodiscard]] std::uint16_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint16_t value;
};
}
