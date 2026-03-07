#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/iterators/MessageIterator.hpp"
#include "../protocol/iterators/MessageBlockIterator.hpp"

namespace statistics {

// Nasdaq Itch C++ statistics
struct Statistics {

    nasdaq::nsmequities::totalview::itch::v5_0::MessageIterator message;
    nasdaq::nsmequities::totalview::itch::v5_0::MessageBlockIterator message_block;
    packet::Parser& parser;
    const statistics::Options& options;

    // counters
    uint64_t total_packets = 0;
    uint64_t unknown_packets = 0;
    uint64_t total_messages = 0;
    uint64_t unknown_messages = 0;
    uint64_t heartbeats = 0;

    // message counters
    uint64_t system_event_message = 0;
    uint64_t stock_directory_message = 0;
    uint64_t stock_trading_action_message = 0;
    uint64_t reg_sho_short_sale_price_test_restricted_indicator_message = 0;
    uint64_t market_participant_position_message = 0;
    uint64_t mwcb_decline_level_message = 0;
    uint64_t mwcb_status_level_message = 0;
    uint64_t ipo_quoting_period_update = 0;
    uint64_t luld_auction_collar_message = 0;
    uint64_t operational_halt_message = 0;
    uint64_t add_order_no_mpid_attribution_message = 0;
    uint64_t add_order_with_mpid_attribution_message = 0;
    uint64_t order_executed_message = 0;
    uint64_t order_executed_with_price_message = 0;
    uint64_t order_cancel_message = 0;
    uint64_t order_delete_message = 0;
    uint64_t order_replace_message = 0;
    uint64_t non_cross_trade_message = 0;
    uint64_t cross_trade_message = 0;
    uint64_t broken_trade_message = 0;
    uint64_t net_order_imbalance_indicator_message = 0;
    uint64_t retail_price_improvement_indicator_message = 0;
    uint64_t direct_listing_with_capital_raise_price_discovery_message = 0;

    explicit Statistics(const statistics::Options& options, packet::Parser& parser)
     : parser{ parser }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        message_block.initialize(frame.payload, frame.payload_len);

        if (message_block.message_count == 0) {
            ++heartbeats;
            return;
        }

        if (message_block.message_count == 65535) {
            ++heartbeats;
            return;
        }

        while (message_block.next()) {
            process(message_block.message, message_block.message_type);
        }
    }

    // process message
    void process(const std::byte* pointer, const char message_type) {
        ++total_messages;

        switch (message_type) {
            case 'S':
                ++system_event_message;
                break;
            case 'R':
                ++stock_directory_message;
                break;
            case 'H':
                ++stock_trading_action_message;
                break;
            case 'Y':
                ++reg_sho_short_sale_price_test_restricted_indicator_message;
                break;
            case 'L':
                ++market_participant_position_message;
                break;
            case 'V':
                ++mwcb_decline_level_message;
                break;
            case 'W':
                ++mwcb_status_level_message;
                break;
            case 'K':
                ++ipo_quoting_period_update;
                break;
            case 'J':
                ++luld_auction_collar_message;
                break;
            case 'h':
                ++operational_halt_message;
                break;
            case 'A':
                ++add_order_no_mpid_attribution_message;
                break;
            case 'F':
                ++add_order_with_mpid_attribution_message;
                break;
            case 'E':
                ++order_executed_message;
                break;
            case 'C':
                ++order_executed_with_price_message;
                break;
            case 'X':
                ++order_cancel_message;
                break;
            case 'D':
                ++order_delete_message;
                break;
            case 'U':
                ++order_replace_message;
                break;
            case 'P':
                ++non_cross_trade_message;
                break;
            case 'Q':
                ++cross_trade_message;
                break;
            case 'B':
                ++broken_trade_message;
                break;
            case 'I':
                ++net_order_imbalance_indicator_message;
                break;
            case 'N':
                ++retail_price_improvement_indicator_message;
                break;
            case 'O':
                ++direct_listing_with_capital_raise_price_discovery_message;
                break;

            default:
                ++unknown_messages;
                if (options.verbose) {
                    std::cerr << "Unknown message_type: " << static_cast<int>(message_type) << std::endl;
                }
                break;
        }
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
        std::cout << "  SystemEventMessage (S)                                  " << system_event_message << std::endl;
        std::cout << "  StockDirectoryMessage (R)                               " << stock_directory_message << std::endl;
        std::cout << "  StockTradingActionMessage (H)                           " << stock_trading_action_message << std::endl;
        std::cout << "  RegShoShortSalePriceTestRestrictedIndicatorMessage (Y)  " << reg_sho_short_sale_price_test_restricted_indicator_message << std::endl;
        std::cout << "  MarketParticipantPositionMessage (L)                    " << market_participant_position_message << std::endl;
        std::cout << "  MwcbDeclineLevelMessage (V)                             " << mwcb_decline_level_message << std::endl;
        std::cout << "  MwcbStatusLevelMessage (W)                              " << mwcb_status_level_message << std::endl;
        std::cout << "  IpoQuotingPeriodUpdate (K)                              " << ipo_quoting_period_update << std::endl;
        std::cout << "  LuldAuctionCollarMessage (J)                            " << luld_auction_collar_message << std::endl;
        std::cout << "  OperationalHaltMessage (h)                              " << operational_halt_message << std::endl;
        std::cout << "  AddOrderNoMpidAttributionMessage (A)                    " << add_order_no_mpid_attribution_message << std::endl;
        std::cout << "  AddOrderWithMpidAttributionMessage (F)                  " << add_order_with_mpid_attribution_message << std::endl;
        std::cout << "  OrderExecutedMessage (E)                                " << order_executed_message << std::endl;
        std::cout << "  OrderExecutedWithPriceMessage (C)                       " << order_executed_with_price_message << std::endl;
        std::cout << "  OrderCancelMessage (X)                                  " << order_cancel_message << std::endl;
        std::cout << "  OrderDeleteMessage (D)                                  " << order_delete_message << std::endl;
        std::cout << "  OrderReplaceMessage (U)                                 " << order_replace_message << std::endl;
        std::cout << "  NonCrossTradeMessage (P)                                " << non_cross_trade_message << std::endl;
        std::cout << "  CrossTradeMessage (Q)                                   " << cross_trade_message << std::endl;
        std::cout << "  BrokenTradeMessage (B)                                  " << broken_trade_message << std::endl;
        std::cout << "  NetOrderImbalanceIndicatorMessage (I)                   " << net_order_imbalance_indicator_message << std::endl;
        std::cout << "  RetailPriceImprovementIndicatorMessage (N)              " << retail_price_improvement_indicator_message << std::endl;
        std::cout << "  DirectListingWithCapitalRaisePriceDiscoveryMessage (O)  " << direct_listing_with_capital_raise_price_discovery_message << std::endl;
    }
};
}
