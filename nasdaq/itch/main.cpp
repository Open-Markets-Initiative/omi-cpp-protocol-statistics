#include <iostream>
#include <string>
#include <cstring>

#include "packet/Parser.hpp"
#include "statistics/Statistics.hpp"

// program options
struct Options {
    packet::Options pcap;
    statistics::Options statistics;
};

void print_usage(const char* program) {
    std::cout << "Usage: " << program << " [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -i, --input <file>   Input pcap file (required)" << std::endl;
    std::cout << "  -v, --verbose        Verbose output" << std::endl;
    std::cout << "  -h, --help           Show this help" << std::endl;
}

Options args(const int argc, char** argv) {

    Options options;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--input" || arg == "-i") {
            if (i + 1 < argc) {
                options.pcap.file = argv[++i];
            } else {
                std::cerr << "Error: --input requires a file path" << std::endl;
                exit(1);
            }
        }
        else if (arg == "--verbose" || arg == "-v") {
            options.statistics.verbose = true;
        }
        else if (arg == "--help" || arg == "-h") {
            print_usage(argv[0]);
            exit(0);
        }
        else {
            std::cerr << "Unknown option: " << arg << std::endl;
            print_usage(argv[0]);
            exit(1);
        }
    }

    if (options.pcap.file.empty()) {
        std::cerr << "Error: --input is required" << std::endl;
        print_usage(argv[0]);
        exit(1);
    }

    return options;
}

int main(const int argc, char** argv) {
    try {
        const auto options = args(argc, argv);

        packet::Parser parser{ options.pcap };
        statistics::Statistics statistics{ options.statistics, parser };

        while (parser.next()) {
            ++statistics.total_packets;
            if (parser.identify() == packet::result::nasdaq_nsmequities_totalview_itch_v5_0) {
                statistics.udp();
            } else {
                ++statistics.unknown_packets;
            }
        }

        statistics.report();
        return 0;
    }
    catch (const std::exception &exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown exception" << std::endl;
        return 1;
    }
}