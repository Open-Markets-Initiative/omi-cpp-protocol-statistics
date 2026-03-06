#pragma once

#include "PcapFile.hpp"
#include "ZipPcap.hpp"
#include "Frame.hpp"
#include "Settings.hpp"
#include "Result.hpp"
#include "decompressor/Detect.hpp"

namespace packet {

    // pcap parser
    struct Parser {

        std::unique_ptr<packet::PcapSource> source;
        packet::Frame current_frame;

        const packet::Options& options;

        explicit Parser(const packet::Options& options)
          : options{ options }, source{ open_source(options.file) } {}

        // load next pcap frame
        bool next() {
            return source->advance();
        }

        // parse frame and identify protocol
        result identify() {
            current_frame = packet::Frame{ source->data(), source->length() };

            if (current_frame.is_udp()) {
                return result::nasdaq_nsmequities_totalview_itch_v5_0;
            }

            return result::unknown;
        }

        // get current frame
        const Frame& frame() const {
            return current_frame;
        }

    private:

        static std::unique_ptr<PcapSource> open_source(const std::string& path) {
#ifdef HAS_ZLIB
            if (is_zip_file(path)) {
                FILE* fp = std::fopen(path.c_str(), "rb");
                if (!fp) throw std::runtime_error("cannot open: " + path);
                return std::make_unique<ZipPcapSource>(fp);
            }
#endif
            return std::make_unique<PcapFile>(path);
        }
    };
}