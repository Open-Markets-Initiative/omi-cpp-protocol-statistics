#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Message Type
struct MessageType {

    static constexpr const char* name = "Message Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr MessageType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MessageType(const char value)
     : value{ value } {}

    // get value of MessageType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
