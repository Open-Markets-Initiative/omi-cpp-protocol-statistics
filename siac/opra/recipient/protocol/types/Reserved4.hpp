#pragma once

#include <array>
#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Four Reserved Bytes
struct Reserved4 {

    static constexpr const char* name = "Reserved 4";
    static constexpr std::size_t size = 4;

    // underlying type
    using type = std::array<std::uint8_t, size>;

    // default constructor
    constexpr Reserved4()
     : value{} {}

  protected:
    type value;
};
}
