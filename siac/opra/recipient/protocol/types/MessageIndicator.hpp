#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Message Identifier
struct MessageIndicator {

    static constexpr const char* name = "Message Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr MessageIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MessageIndicator(const char value)
     : value{ value } {}

    // get value of MessageIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
