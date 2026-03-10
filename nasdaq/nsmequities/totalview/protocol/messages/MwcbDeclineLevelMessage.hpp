#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Level1.hpp"
#include "../types/Level2.hpp"
#include "../types/Level3.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Informs data recipients what the daily MWCB breach points are set to for the current trading day.
struct MwcbDeclineLevelMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    Level1 level_1;
    Level2 level_2;
    Level3 level_3;

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
