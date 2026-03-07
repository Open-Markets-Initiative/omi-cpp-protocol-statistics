#pragma once

#include <cstddef>

namespace iex::equities::deepplus::iextp::v1_0_1 {

// Operational halt status identifier
struct OperationalHaltStatus {

    static constexpr const char* name = "Operational Halt Status";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr OperationalHaltStatus()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OperationalHaltStatus(const char value)
     : value{ value } {}

    // get value of OperationalHaltStatus field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
