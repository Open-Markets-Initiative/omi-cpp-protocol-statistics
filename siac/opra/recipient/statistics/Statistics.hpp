#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/definitions.hpp"

namespace statistics {

// Siac Obi C++ statistics
struct Statistics {

    siac::opra::recipient::obi::v6_1::MessageIterator message;
    packet::Parser& parser;
    const statistics::Options& options;

    // counters
    uint64_t total_packets = 0;
    uint64_t unknown_packets = 0;
    uint64_t total_messages = 0;
    uint64_t unknown_messages = 0;
    uint64_t heartbeats = 0;

    // message counters
    uint64_t equity_and_index_last_sale_message = 0;
    uint64_t open_interest_message = 0;
    uint64_t equity_and_index_end_of_day_summary_message = 0;
    uint64_t long_equity_and_index_quote_message = 0;
    uint64_t short_equity_and_index_quote_message = 0;
    uint64_t administrative_message = 0;
    uint64_t control_message = 0;
    uint64_t underlying_value_message = 0;
    uint64_t underlying_value_last_sale_message = 0;
    uint64_t underlying_value_bid_and_offer_message = 0;

    explicit Statistics(const statistics::Options& options, packet::Parser& parser)
     : parser{ parser }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        message.initialize(frame.payload);

        while (message.next()) {
            const auto* header = siac::opra::recipient::obi::v6_1::Message::parse(message.entry);
            auto consumed = sizeof(siac::opra::recipient::obi::v6_1::Message) + process(message.entry + sizeof(siac::opra::recipient::obi::v6_1::Message), header->message_category.get());
            message.advance(consumed);
        }
    }

    // process message
    std::size_t process(const std::byte* pointer, const char message_category) {
        ++total_messages;

        switch (message_category) {
            case 'a':
                ++equity_and_index_last_sale_message;
                return sizeof(siac::opra::recipient::obi::v6_1::EquityAndIndexLastSaleMessage);
            case 'd':
                ++open_interest_message;
                return sizeof(siac::opra::recipient::obi::v6_1::OpenInterestMessage);
            case 'f':
                ++equity_and_index_end_of_day_summary_message;
                return sizeof(siac::opra::recipient::obi::v6_1::EquityAndIndexEndOfDaySummaryMessage);
            case 'k':
                ++long_equity_and_index_quote_message;
                {
                    const auto* body = siac::opra::recipient::obi::v6_1::LongEquityAndIndexQuoteMessage::parse(pointer);
                    std::size_t sz = sizeof(siac::opra::recipient::obi::v6_1::LongEquityAndIndexQuoteMessage) - sizeof(siac::opra::recipient::obi::v6_1::BestBidAppendage) - sizeof(siac::opra::recipient::obi::v6_1::BestOfferAppendage) - sizeof(siac::opra::recipient::obi::v6_1::BestBidAndOfferAppendage);
                    if (body->bbo_indicator.get() == 'M' || body->bbo_indicator.get() == 'N' || body->bbo_indicator.get() == 'P') sz += sizeof(siac::opra::recipient::obi::v6_1::BestBidAppendage);
                    if (body->bbo_indicator.get() == 'C' || body->bbo_indicator.get() == 'G' || body->bbo_indicator.get() == 'K') sz += sizeof(siac::opra::recipient::obi::v6_1::BestOfferAppendage);
                    if (body->bbo_indicator.get() == 'O') sz += sizeof(siac::opra::recipient::obi::v6_1::BestBidAndOfferAppendage);
                    return sz;
                }
            case 'q':
                ++short_equity_and_index_quote_message;
                {
                    const auto* body = siac::opra::recipient::obi::v6_1::ShortEquityAndIndexQuoteMessage::parse(pointer);
                    std::size_t sz = sizeof(siac::opra::recipient::obi::v6_1::ShortEquityAndIndexQuoteMessage) - sizeof(siac::opra::recipient::obi::v6_1::BestBidAppendage) - sizeof(siac::opra::recipient::obi::v6_1::BestOfferAppendage);
                    if (body->bbo_indicator.get() == 'M' || body->bbo_indicator.get() == 'N' || body->bbo_indicator.get() == 'P') sz += sizeof(siac::opra::recipient::obi::v6_1::BestBidAppendage);
                    if (body->bbo_indicator.get() == 'C' || body->bbo_indicator.get() == 'G' || body->bbo_indicator.get() == 'K') sz += sizeof(siac::opra::recipient::obi::v6_1::BestOfferAppendage);
                    return sz;
                }
            case 'C':
                ++administrative_message;
                {
                    const auto* body = siac::opra::recipient::obi::v6_1::AdministrativeMessage::parse(pointer);
                    std::size_t sz = sizeof(siac::opra::recipient::obi::v6_1::AdministrativeMessage);
                    sz += body->message_data_length.get();
                    return sz;
                }
            case 'H':
                ++control_message;
                {
                    const auto* body = siac::opra::recipient::obi::v6_1::ControlMessage::parse(pointer);
                    std::size_t sz = sizeof(siac::opra::recipient::obi::v6_1::ControlMessage);
                    sz += body->message_data_length.get();
                    return sz;
                }
            case 'Y':
                ++underlying_value_message;
                {
                    const auto* sub_header = siac::opra::recipient::obi::v6_1::UnderlyingValueMessage::parse(pointer);
                    const char underlying_value_message_type = sub_header->underlying_value_message_type.get();
                    switch (underlying_value_message_type) {
                        case ' ':
                            ++underlying_value_last_sale_message;
                            break;
                        case 'I':
                            ++underlying_value_bid_and_offer_message;
                            break;
                        default:
                            ++unknown_messages;
                            break;
                    }
                }
                return sizeof(siac::opra::recipient::obi::v6_1::UnderlyingValueMessage) + sizeof(siac::opra::recipient::obi::v6_1::UnderlyingValueLastSaleMessage);

            default:
                ++unknown_messages;
                if (options.verbose) {
                    std::cerr << "Unknown message_category: " << static_cast<int>(message_category) << std::endl;
                }
                return 0;
        }
        return 0;
    }

    // report statistics
    void report() {
        std::cout << std::endl;
        std::cout << "Statistics Report" << std::endl;
        std::cout << "=================" << std::endl;
        std::cout << "Total packets:   " << total_packets << std::endl;
        std::cout << "Unknown packets: " << unknown_packets << std::endl;
        std::cout << "Total messages:  " << total_messages << std::endl;
        std::cout << "Unknown types:   " << unknown_messages << std::endl;
        std::cout << "Heartbeats:      " << heartbeats << std::endl;

        std::cout << std::endl;
        std::cout << "Message Counts:" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "  EquityAndIndexLastSaleMessage (a)         " << equity_and_index_last_sale_message << std::endl;
        std::cout << "  OpenInterestMessage (d)                   " << open_interest_message << std::endl;
        std::cout << "  EquityAndIndexEndOfDaySummaryMessage (f)  " << equity_and_index_end_of_day_summary_message << std::endl;
        std::cout << "  LongEquityAndIndexQuoteMessage (k)        " << long_equity_and_index_quote_message << std::endl;
        std::cout << "  ShortEquityAndIndexQuoteMessage (q)       " << short_equity_and_index_quote_message << std::endl;
        std::cout << "  AdministrativeMessage (C)                 " << administrative_message << std::endl;
        std::cout << "  ControlMessage (H)                        " << control_message << std::endl;
        std::cout << "  UnderlyingValueMessage (Y)                " << underlying_value_message << std::endl;
        std::cout << "  UnderlyingValueLastSaleMessage ( )        " << underlying_value_last_sale_message << std::endl;
        std::cout << "  UnderlyingValueBidAndOfferMessage (I)     " << underlying_value_bid_and_offer_message << std::endl;
    }
};
}
