#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Price At Which A Seller Is Offering To Sell An Option
struct OfferPrice {

    static constexpr const char* name = "Offer Price";
    static constexpr std::size_t size = 4;
    using type = std::int32_t;

    // default constructor
    constexpr OfferPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OfferPrice(const std::int32_t value)
     : value{ std::byteswap(value) } {}

    // get value of OfferPrice field
    [[nodiscard]] std::int32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int32_t value;
};
}
