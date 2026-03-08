#pragma once

#include "../types/TransactTime.hpp"
#include "../types/QuoteReqId.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding3.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// QuoteRequest
struct QuoteRequest {

    sbe::TransactTime TransactTime;
    sbe::QuoteReqId QuoteReqId;
    sbe::MatchEventIndicator MatchEventIndicator;
    sbe::Padding3 Padding3;

    // parse method
    static QuoteRequest* parse(std::byte* buffer) {
        return reinterpret_cast<QuoteRequest*>(buffer);
    }

    // parse method const
    static const QuoteRequest* parse(const std::byte* buffer) {
        return reinterpret_cast<const QuoteRequest*>(buffer);
    }
};

#pragma pack(pop)
}
