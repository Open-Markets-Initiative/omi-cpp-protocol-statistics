#pragma once

#ifdef HAS_ZLIB

#include "PcapSource.hpp"
#include "PcapFile.hpp"
#include "decompressor/Detect.hpp"
#include "decompressor/ZipDecompressor.hpp"

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>

namespace packet {

// Zip pcap source — reads all pcap entries from a zip archive sequentially.
// Each zip entry is decompressed (deflate), then further decompressed
// (detect_and_wrap handles zstd/gzip/etc), then parsed as a pcap file.
struct ZipPcapSource : PcapSource {
    FILE* file_;
    std::unique_ptr<PcapFile> current_;
    long next_entry_offset_ = 0;
    bool all_done_ = false;

    explicit ZipPcapSource(FILE* fp) : file_(fp) {
        advance_entry();
    }

    ~ZipPcapSource() override {
        if (file_) std::fclose(file_);
    }

    ZipPcapSource(const ZipPcapSource&) = delete;
    ZipPcapSource& operator=(const ZipPcapSource&) = delete;

    bool advance() override {
        while (true) {
            if (current_ && current_->advance()) return true;

            // Current pcap exhausted — move to next zip entry
            current_.reset();
            if (!advance_entry()) {
                all_done_ = true;
                return false;
            }
        }
    }

    std::uint64_t timestamp_ns() const override { return current_->timestamp_ns(); }
    const std::byte* data() const override { return current_->data(); }
    std::uint32_t length() const override { return current_->length(); }
    bool done() const override { return all_done_; }

private:

    bool advance_entry() {
        // Seek to the start of the next entry (skip any unread compressed data)
        if (next_entry_offset_ > 0) {
            std::fseek(file_, next_entry_offset_, SEEK_SET);
        }

        auto header = ZipLocalHeader::parse(file_);
        if (!header.valid) return false;

        // Record where the next entry starts (after this entry's compressed data)
        next_entry_offset_ = header.data_offset + header.compressed_size;

        auto entry = std::make_unique<ZipEntryDecompressor>(file_, header);
        auto decompressed = detect_and_wrap(std::move(entry));

        try {
            current_ = std::make_unique<PcapFile>(std::move(decompressed));
            return true;
        } catch (...) {
            return false;
        }
    }
};

} // namespace packet

#endif