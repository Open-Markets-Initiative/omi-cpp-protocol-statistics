#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Message Identifier
struct MessageCategory {

    static constexpr const char* name = "Message Category";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr MessageCategory()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MessageCategory(const char value)
     : value{ value } {}

    // get value of MessageCategory field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
