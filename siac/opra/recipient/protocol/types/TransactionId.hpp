#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Reserved For Internal Use Only
struct TransactionId {

    static constexpr const char* name = "Transaction Id";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr TransactionId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TransactionId(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of TransactionId field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
