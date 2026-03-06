#pragma once

#include "../types/Version.hpp"
#include "../types/Reserved.hpp"
#include "../types/MessageProtocolId.hpp"
#include "../types/ChannelId.hpp"
#include "../types/SessionId.hpp"
#include "../types/PayloadLength.hpp"
#include "../types/MessageCount.hpp"
#include "../types/StreamOffset.hpp"
#include "../types/FirstMessageSequenceNumber.hpp"
#include "../types/SendTime.hpp"

namespace iex::equities::deepplus::iextp::v1_0_1 {

namespace iextp = iex::equities::deepplus::iextp::v1_0_1;

#pragma pack(push, 1)

struct IextpHeader {

    iextp::Version Version;
    iextp::Reserved Reserved;
    iextp::MessageProtocolId MessageProtocolId;
    iextp::ChannelId ChannelId;
    iextp::SessionId SessionId;
    iextp::PayloadLength PayloadLength;
    iextp::MessageCount MessageCount;
    iextp::StreamOffset StreamOffset;
    iextp::FirstMessageSequenceNumber FirstMessageSequenceNumber;
    iextp::SendTime SendTime;

    // parse method
    static IextpHeader* parse(std::byte* buffer) {
        return reinterpret_cast<IextpHeader*>(buffer);
    }

    // parse method const
    static const IextpHeader* parse(const std::byte* buffer) {
        return reinterpret_cast<const IextpHeader*>(buffer);
    }
};

#pragma pack(pop)
}
