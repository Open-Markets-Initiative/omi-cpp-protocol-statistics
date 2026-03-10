#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Contains Either A Space Not A Retransmitted Message Or V Indicating A Retransmission Of The Block
struct RetransmissionIndicator {

    static constexpr const char* name = "Retransmission Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr RetransmissionIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit RetransmissionIndicator(const char value)
     : value{ value } {}

    // get value of RetransmissionIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
