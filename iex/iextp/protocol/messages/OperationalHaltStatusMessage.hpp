#pragma once

#include "../types/OperationalHaltStatus.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

// The Exchange may suspend trading of one or more securities on IEX for operational reasons and indicates such operational halt using the Operational Halt Status Message.
struct OperationalHaltStatusMessage {

    iextp::OperationalHaltStatus OperationalHaltStatus;
    iextp::Timestamp Timestamp;
    iextp::Symbol Symbol;

    // parse method
    static OperationalHaltStatusMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OperationalHaltStatusMessage*>(buffer);
    }

    // parse method const
    static const OperationalHaltStatusMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OperationalHaltStatusMessage*>(buffer);
    }
};

#pragma pack(pop)
}
