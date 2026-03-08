#pragma once

#include "../types/EventType.hpp"
#include "../types/EventTime.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

struct EventsGroup {

    sbe::EventType EventType;
    sbe::EventTime EventTime;

    // parse method
    static EventsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<EventsGroup*>(buffer);
    }

    // parse method const
    static const EventsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const EventsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
