#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Designates The Opra Binary Version
struct Version {

    static constexpr const char* name = "Version";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type static_value = 6;

    // default constructor
    constexpr Version()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Version(const std::uint8_t value)
     : value{ value } {}

    // get value of Version field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
