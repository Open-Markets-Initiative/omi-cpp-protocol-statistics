#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Indicates The Expiration Month And Identifies The Option As A Call Or A Put
struct ExpirationMonth {

    static constexpr const char* name = "Expiration Month";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ExpirationMonth()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ExpirationMonth(const char value)
     : value{ value } {}

    // get value of ExpirationMonth field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
