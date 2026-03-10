#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// The Offer Index Value Represents The Value Of The Indexs Calculation Formula Using The Current Offer Values Of The Component Securities
struct OfferIndexValue {

    static constexpr const char* name = "Offer Index Value";
    static constexpr std::size_t size = 8;
    using type = std::int64_t;

    // default constructor
    constexpr OfferIndexValue()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OfferIndexValue(const std::int64_t value)
     : value{ std::byteswap(value) } {}

    // get value of OfferIndexValue field
    [[nodiscard]] std::int64_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::int64_t value;
};
}
