#include <gtest/gtest.h>
#include <filesystem>
#include "../statistics/Statistics.hpp"

TEST(SimpleBinaryEncoding, ProcessPcap) {
    const std::string pcap_path = "omi-data-pcaps/Cme/Mdp3.Sbe.v1.9/MdIncrementalRefreshBook.pcap";

    ASSERT_TRUE(std::filesystem::exists(pcap_path)) << "Pcap file not found: " << pcap_path;

    statistics::Options options;
    options.input = pcap_path;
    packet::Parser parser;
    parser.open(pcap_path);
    statistics::Statistics stats(options, parser);

    while (parser.next()) {
        ++stats.total_packets;
        stats.udp();
    }

    EXPECT_GT(stats.total_packets, 0) << "No packets processed";
    EXPECT_GT(stats.total_messages, 0) << "No messages processed";
    EXPECT_EQ(stats.unknown_messages, 0) << "Unknown messages found";
}
