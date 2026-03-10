#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Underlying Value Message Type
struct UnderlyingValueMessageType {

    static constexpr const char* name = "Underlying Value Message Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr UnderlyingValueMessageType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingValueMessageType(const char value)
     : value{ value } {}

    // get value of UnderlyingValueMessageType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
