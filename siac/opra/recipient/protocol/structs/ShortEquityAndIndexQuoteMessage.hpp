#pragma once

#include "../types/QuoteMessageType.hpp"
#include "../types/BboIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/SecuritySymbolShort.hpp"
#include "../structs/ExpirationBlock.hpp"
#include "../types/StrikePriceShort.hpp"
#include "../types/BidPriceShort.hpp"
#include "../types/BidSizeShort.hpp"
#include "../types/OfferPriceShort.hpp"
#include "../types/OfferSizeShort.hpp"
#include "../structs/BestBidAppendage.hpp"
#include "../structs/BestOfferAppendage.hpp"

namespace siac::opra::recipient::obi::v6_1 {

#pragma pack(push, 1)

struct ShortEquityAndIndexQuoteMessage {

    QuoteMessageType quote_message_type;
    BboIndicator bbo_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    SecuritySymbolShort security_symbol_short;
    ExpirationBlock expiration_block;
    StrikePriceShort strike_price_short;
    BidPriceShort bid_price_short;
    BidSizeShort bid_size_short;
    OfferPriceShort offer_price_short;
    OfferSizeShort offer_size_short;
    BestBidAppendage best_bid_appendage;
    BestOfferAppendage best_offer_appendage;

    // parse method
    static ShortEquityAndIndexQuoteMessage* parse(std::byte* buffer) {
        return reinterpret_cast<ShortEquityAndIndexQuoteMessage*>(buffer);
    }

    // parse method const
    static const ShortEquityAndIndexQuoteMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const ShortEquityAndIndexQuoteMessage*>(buffer);
    }
};

#pragma pack(pop)
}
