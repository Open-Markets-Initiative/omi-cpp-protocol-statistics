#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// 0 X 00 For Regular Trading Session
struct SessionIndicator {

    static constexpr const char* name = "Session Indicator";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr SessionIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SessionIndicator(const std::uint8_t value)
     : value{ value } {}

    // get value of SessionIndicator field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
