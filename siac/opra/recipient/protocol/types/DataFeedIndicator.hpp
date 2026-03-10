#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Value Is‘ O For Opra
struct DataFeedIndicator {

    static constexpr const char* name = "Data Feed Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr DataFeedIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DataFeedIndicator(const char value)
     : value{ value } {}

    // get value of DataFeedIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
