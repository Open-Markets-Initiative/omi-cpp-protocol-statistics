#pragma once

#include <cstddef>

namespace iex::equities::deepplus::iextp::v1_0_1 {

// Trading status identifier
struct TradingStatus {

    static constexpr const char* name = "Trading Status";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr TradingStatus()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TradingStatus(const char value)
     : value{ value } {}

    // get value of TradingStatus field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
