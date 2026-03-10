#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Change In The Price Of An Option From The Closing Price Of One Day To The Closing Price On The Next Day On Which The Option Is Traded
struct NetChange {

    static constexpr const char* name = "Net Change";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr NetChange()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NetChange(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of NetChange field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
