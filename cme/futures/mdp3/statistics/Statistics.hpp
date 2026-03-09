#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/definitions.hpp"

namespace statistics {

// Cme Sbe C++ statistics
struct Statistics {

    cme::mdp3::v13::MessageIterator message;
    packet::Parser& parser;
    const statistics::Options& options;

    // counters
    uint64_t total_packets = 0;
    uint64_t unknown_packets = 0;
    uint64_t total_messages = 0;
    uint64_t unknown_messages = 0;
    uint64_t heartbeats = 0;

    // message counters
    uint64_t channel_reset = 0;
    uint64_t admin_login = 0;
    uint64_t admin_logout = 0;
    uint64_t security_status = 0;
    uint64_t md_incremental_refresh_volume = 0;
    uint64_t quote_request = 0;
    uint64_t md_incremental_refresh_book = 0;
    uint64_t md_incremental_refresh_order_book = 0;
    uint64_t md_incremental_refresh_trade_summary = 0;
    uint64_t md_incremental_refresh_daily_statistics = 0;
    uint64_t md_incremental_refresh_limits_banding = 0;
    uint64_t md_incremental_refresh_session_statistics = 0;
    uint64_t snapshot_full_refresh = 0;
    uint64_t snapshot_full_refresh_order_book = 0;
    uint64_t md_instrument_definition_future = 0;
    uint64_t md_instrument_definition_option = 0;
    uint64_t md_instrument_definition_spread = 0;
    uint64_t md_instrument_definition_fixed_income = 0;
    uint64_t md_instrument_definition_repo = 0;
    uint64_t snapshot_refresh_top_orders = 0;
    uint64_t security_status_workup = 0;
    uint64_t snapshot_full_refresh_tcp = 0;
    uint64_t collateral_market_value = 0;
    uint64_t md_instrument_definition_fx = 0;
    uint64_t md_incremental_refresh_book_long_qty = 0;
    uint64_t md_incremental_refresh_trade_summary_long_qty = 0;
    uint64_t md_incremental_refresh_volume_long_qty = 0;
    uint64_t md_incremental_refresh_session_statistics_long_qty = 0;
    uint64_t snapshot_full_refresh_tcp_long_qty = 0;
    uint64_t snapshot_full_refresh_long_qty = 0;

    explicit Statistics(const statistics::Options& options, packet::Parser& parser)
     : parser{ parser }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        message.initialize(frame.payload, frame.payload_len);

        if (message.template_id == 12) {
            ++heartbeats;
            return;
        }

        while (message.next()) {
            process(message.message, message.template_id);
        }
    }

    // process message
    void process(const std::byte* pointer, const std::uint16_t template_id) {
        ++total_messages;

        switch (template_id) {
            case 4:
                ++channel_reset;
                break;
            case 15:
                ++admin_login;
                break;
            case 16:
                ++admin_logout;
                break;
            case 30:
                ++security_status;
                break;
            case 37:
                ++md_incremental_refresh_volume;
                break;
            case 39:
                ++quote_request;
                break;
            case 46:
                ++md_incremental_refresh_book;
                break;
            case 47:
                ++md_incremental_refresh_order_book;
                break;
            case 48:
                ++md_incremental_refresh_trade_summary;
                break;
            case 49:
                ++md_incremental_refresh_daily_statistics;
                break;
            case 50:
                ++md_incremental_refresh_limits_banding;
                break;
            case 51:
                ++md_incremental_refresh_session_statistics;
                break;
            case 52:
                ++snapshot_full_refresh;
                break;
            case 53:
                ++snapshot_full_refresh_order_book;
                break;
            case 54:
                ++md_instrument_definition_future;
                break;
            case 55:
                ++md_instrument_definition_option;
                break;
            case 56:
                ++md_instrument_definition_spread;
                break;
            case 57:
                ++md_instrument_definition_fixed_income;
                break;
            case 58:
                ++md_instrument_definition_repo;
                break;
            case 59:
                ++snapshot_refresh_top_orders;
                break;
            case 60:
                ++security_status_workup;
                break;
            case 61:
                ++snapshot_full_refresh_tcp;
                break;
            case 62:
                ++collateral_market_value;
                break;
            case 63:
                ++md_instrument_definition_fx;
                break;
            case 64:
                ++md_incremental_refresh_book_long_qty;
                break;
            case 65:
                ++md_incremental_refresh_trade_summary_long_qty;
                break;
            case 66:
                ++md_incremental_refresh_volume_long_qty;
                break;
            case 67:
                ++md_incremental_refresh_session_statistics_long_qty;
                break;
            case 68:
                ++snapshot_full_refresh_tcp_long_qty;
                break;
            case 69:
                ++snapshot_full_refresh_long_qty;
                break;

            default:
                ++unknown_messages;
                if (options.verbose) {
                    std::cerr << "Unknown template_id: " << static_cast<int>(template_id) << std::endl;
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
        std::cout << "  ChannelReset (4)                                   " << channel_reset << std::endl;
        std::cout << "  AdminLogin (15)                                    " << admin_login << std::endl;
        std::cout << "  AdminLogout (16)                                   " << admin_logout << std::endl;
        std::cout << "  SecurityStatus (30)                                " << security_status << std::endl;
        std::cout << "  MdIncrementalRefreshVolume (37)                    " << md_incremental_refresh_volume << std::endl;
        std::cout << "  QuoteRequest (39)                                  " << quote_request << std::endl;
        std::cout << "  MdIncrementalRefreshBook (46)                      " << md_incremental_refresh_book << std::endl;
        std::cout << "  MdIncrementalRefreshOrderBook (47)                 " << md_incremental_refresh_order_book << std::endl;
        std::cout << "  MdIncrementalRefreshTradeSummary (48)              " << md_incremental_refresh_trade_summary << std::endl;
        std::cout << "  MdIncrementalRefreshDailyStatistics (49)           " << md_incremental_refresh_daily_statistics << std::endl;
        std::cout << "  MdIncrementalRefreshLimitsBanding (50)             " << md_incremental_refresh_limits_banding << std::endl;
        std::cout << "  MdIncrementalRefreshSessionStatistics (51)         " << md_incremental_refresh_session_statistics << std::endl;
        std::cout << "  SnapshotFullRefresh (52)                           " << snapshot_full_refresh << std::endl;
        std::cout << "  SnapshotFullRefreshOrderBook (53)                  " << snapshot_full_refresh_order_book << std::endl;
        std::cout << "  MdInstrumentDefinitionFuture (54)                  " << md_instrument_definition_future << std::endl;
        std::cout << "  MdInstrumentDefinitionOption (55)                  " << md_instrument_definition_option << std::endl;
        std::cout << "  MdInstrumentDefinitionSpread (56)                  " << md_instrument_definition_spread << std::endl;
        std::cout << "  MdInstrumentDefinitionFixedIncome (57)             " << md_instrument_definition_fixed_income << std::endl;
        std::cout << "  MdInstrumentDefinitionRepo (58)                    " << md_instrument_definition_repo << std::endl;
        std::cout << "  SnapshotRefreshTopOrders (59)                      " << snapshot_refresh_top_orders << std::endl;
        std::cout << "  SecurityStatusWorkup (60)                          " << security_status_workup << std::endl;
        std::cout << "  SnapshotFullRefreshTcp (61)                        " << snapshot_full_refresh_tcp << std::endl;
        std::cout << "  CollateralMarketValue (62)                         " << collateral_market_value << std::endl;
        std::cout << "  MdInstrumentDefinitionFx (63)                      " << md_instrument_definition_fx << std::endl;
        std::cout << "  MdIncrementalRefreshBookLongQty (64)               " << md_incremental_refresh_book_long_qty << std::endl;
        std::cout << "  MdIncrementalRefreshTradeSummaryLongQty (65)       " << md_incremental_refresh_trade_summary_long_qty << std::endl;
        std::cout << "  MdIncrementalRefreshVolumeLongQty (66)             " << md_incremental_refresh_volume_long_qty << std::endl;
        std::cout << "  MdIncrementalRefreshSessionStatisticsLongQty (67)  " << md_incremental_refresh_session_statistics_long_qty << std::endl;
        std::cout << "  SnapshotFullRefreshTcpLongQty (68)                 " << snapshot_full_refresh_tcp_long_qty << std::endl;
        std::cout << "  SnapshotFullRefreshLongQty (69)                    " << snapshot_full_refresh_long_qty << std::endl;
    }
};
}
