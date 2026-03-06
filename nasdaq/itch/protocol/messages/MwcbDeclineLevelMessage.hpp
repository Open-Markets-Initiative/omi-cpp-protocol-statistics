#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Level1.hpp"
#include "../types/Level2.hpp"
#include "../types/Level3.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

namespace itch = nasdaq::nsmequities::totalview::itch::v5_0;

#pragma pack(push, 1)

// Informs data recipients what the daily MWCB breach points are set to for the current trading day.
struct MwcbDeclineLevelMessage {

    itch::StockLocate StockLocate;
    itch::TrackingNumber TrackingNumber;
    itch::Timestamp Timestamp;
    itch::Level1 Level1;
    itch::Level2 Level2;
    itch::Level3 Level3;

    // parse method
    static MwcbDeclineLevelMessage* parse(std::byte* buffer) {
        return reinterpret_cast<MwcbDeclineLevelMessage*>(buffer);
    }

    // parse method const
    static const MwcbDeclineLevelMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const MwcbDeclineLevelMessage*>(buffer);
    }
};

#pragma pack(pop)
}
