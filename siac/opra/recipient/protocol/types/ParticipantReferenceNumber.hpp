#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_1 {

// The Prn Is For Optional Use By The Participant
struct ParticipantReferenceNumber {

    static constexpr const char* name = "Participant Reference Number";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr ParticipantReferenceNumber()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ParticipantReferenceNumber(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of ParticipantReferenceNumber field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
