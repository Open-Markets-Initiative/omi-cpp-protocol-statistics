#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Total Number Of Outstanding Option Contracts That Have Not Been Exercised And Have Not Yet Reached Expiration
struct OpenInterestVolume {

    static constexpr const char* name = "Open Interest Volume";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr OpenInterestVolume()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OpenInterestVolume(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of OpenInterestVolume field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
