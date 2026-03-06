#pragma once

#include <array>
#include <bit>
#include <cstddef>
#include <cstdint>

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

// Nanoseconds since midnight
struct Timestamp {

    static constexpr const char* name = "Timestamp";
    static constexpr std::size_t size = 6;

    // underlying type
    using type = std::array<std::uint8_t, size>;

    // default constructor
    constexpr Timestamp()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Timestamp(const std::uint64_t value)
     : value{ 0 } {}

    // get value of Timestamp field
    [[nodiscard]] std::uint64_t get() const {
        std::uint64_t result = 0;
        for (auto index = 0; index < size; ++index) {
            result = (result << 8) + value[index];
        }
        return result;

    }

  protected:
    type value;
};
}
