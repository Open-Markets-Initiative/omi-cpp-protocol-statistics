#pragma once

#include <array>
#include <cstddef>

namespace iex::equities::deepplus::iextp::v1_0_1 {

// Reserved byte
struct Reserved {

    static constexpr const char* name = "Reserved";
    static constexpr std::size_t size = 1;

    // underlying type
    using type = std::array<std::uint8_t, size>;

    // default constructor
    constexpr Reserved()
     : value{} {}

  protected:
    type value;
};
}
