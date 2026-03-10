#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_1 {

// Ascii Character That Identifies The Participant Or Processor That Initiated The Message
struct ParticipantId {

    static constexpr const char* name = "Participant Id";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ParticipantId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ParticipantId(const char value)
     : value{ value } {}

    // get value of ParticipantId field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
