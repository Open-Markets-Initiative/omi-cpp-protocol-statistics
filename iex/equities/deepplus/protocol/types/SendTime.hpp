#pragma once

#include <cstddef>
#include <cstdint>

namespace iex::equities::deepplus::iextp::v1_0_1 {

// Send time of segment
struct SendTime {

    static constexpr const char* name = "Send Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr SendTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SendTime(const std::uint64_t value)
     : value{ value } {}

    // get value of SendTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
