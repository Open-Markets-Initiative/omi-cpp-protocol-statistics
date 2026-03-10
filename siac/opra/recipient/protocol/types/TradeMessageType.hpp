#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Trade Message Type
struct TradeMessageType {

    static constexpr const char* name = "Trade Message Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr TradeMessageType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TradeMessageType(const char value)
     : value{ value } {}

    // get value of TradeMessageType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
