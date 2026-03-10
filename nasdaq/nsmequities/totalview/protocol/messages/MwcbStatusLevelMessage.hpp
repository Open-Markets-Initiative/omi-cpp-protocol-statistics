#pragma once

#include "../types/StockLocate.hpp"
#include "../types/TrackingNumber.hpp"
#include "../types/Timestamp.hpp"
#include "../types/BreachedLevel.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

#pragma pack(push, 1)

// Informs data recipients when a MWCB has breached one of the established levels
struct MwcbStatusLevelMessage {

    StockLocate stock_locate;
    TrackingNumber tracking_number;
    Timestamp timestamp;
    BreachedLevel breached_level;

    // parse method
    static MwcbStatusLevelMessage* parse(std::byte* buffer) {
        return reinterpret_cast<MwcbStatusLevelMessage*>(buffer);
    }

    // parse method const
    static const MwcbStatusLevelMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const MwcbStatusLevelMessage*>(buffer);
    }
};

#pragma pack(pop)
}
