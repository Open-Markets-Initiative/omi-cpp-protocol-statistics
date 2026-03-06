#pragma once

#include <cstddef>
#include <cstdint>

namespace iex::equities::deepplus::iextp::v1_0_1 {

// Time stamp of the system event
struct Timestamp {

    static constexpr const char* name = "Timestamp";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr Timestamp()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Timestamp(const std::uint64_t value)
     : value{ value } {}

    // get value of Timestamp field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
