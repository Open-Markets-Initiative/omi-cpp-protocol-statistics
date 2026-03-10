#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Message Data Field
struct MessageData {

    static constexpr const char* name = "Message Data";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr MessageData()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MessageData(const char value)
     : value{ value } {}

    // get value of MessageData field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
