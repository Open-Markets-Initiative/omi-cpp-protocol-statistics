#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Contains The Index Value Using Last Sale Values Of Index Components
struct IndexValue {

    static constexpr const char* name = "Index Value";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr IndexValue()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit IndexValue(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of IndexValue field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
