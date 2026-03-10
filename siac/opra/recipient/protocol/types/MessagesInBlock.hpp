#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// The Number Of Messages Contained In The Block Data Of The Transmission Block
struct MessagesInBlock {

    static constexpr const char* name = "Messages In Block";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr MessagesInBlock()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MessagesInBlock(const std::uint8_t value)
     : value{ value } {}

    // get value of MessagesInBlock field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
