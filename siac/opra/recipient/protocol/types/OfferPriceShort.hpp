#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// Represents The Price At Which A Seller Is Offering To Sell An Option
struct OfferPriceShort {

    static constexpr const char* name = "Offer Price Short";
    static constexpr std::size_t size = 2;
    using type = std::int16_t;

    // default constructor
    constexpr OfferPriceShort()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OfferPriceShort(const std::int16_t value)
     : value{ std::byteswap(value) } {}

    // get value of OfferPriceShort field
    [[nodiscard]] std::int16_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int16_t value;
};
}
