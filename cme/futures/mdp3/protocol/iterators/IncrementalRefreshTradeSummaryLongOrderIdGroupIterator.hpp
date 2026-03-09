#pragma once

#include "../definitions.hpp"

namespace cme::mdp3::v13 {
// IncrementalRefreshTradeSummaryLongOrderIdGroupIterator
struct IncrementalRefreshTradeSummaryLongOrderIdGroupIterator {

    const std::byte* current = nullptr;

    const GroupSize8Byte* group_size_8_byte = nullptr;

    std::uint16_t block_length = 0;
    std::uint8_t num_in_group = 0;
    std::uint8_t entry_index = 0;
    const std::byte* entry = nullptr;

    // initialize group iterator
    void initialize(const std::byte* data) {

        current = data;

        group_size_8_byte = GroupSize8Byte::parse(current);
        current += sizeof(GroupSize8Byte);

        block_length = group_size_8_byte->BlockLength.get();
        num_in_group = group_size_8_byte->NumInGroup.get();
        entry_index = 0;
        entry = nullptr;
    }

    // next entry
    bool next() {

        if (entry_index >= num_in_group) {
            return false;
        }

        entry = current;
        entry_index++;
        current += block_length;

        return true;
    }

    // reset iterator
    void reset() {
        current = nullptr;

        group_size_8_byte = nullptr;

        block_length = 0;
        num_in_group = 0;
        entry_index = 0;
        entry = nullptr;
    }
};
}
