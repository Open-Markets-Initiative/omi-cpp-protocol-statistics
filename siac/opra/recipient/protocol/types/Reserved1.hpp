#pragma once

#include <array>
#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// One Reserved Byte
struct Reserved1 {

    static constexpr const char* name = "Reserved 1";
    static constexpr std::size_t size = 1;

    // underlying type
    using type = std::array<std::uint8_t, size>;

    // default constructor
    constexpr Reserved1()
     : value{} {}

  protected:
    type value;
};
}
