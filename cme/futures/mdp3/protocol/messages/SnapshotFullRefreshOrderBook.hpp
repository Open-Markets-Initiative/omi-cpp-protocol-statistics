#pragma once

#include "../types/LastMsgSeqNumProcessed.hpp"
#include "../types/TotNumReports.hpp"
#include "../types/SecurityId.hpp"
#include "../types/NoChunks.hpp"
#include "../types/CurrentChunk.hpp"
#include "../types/TransactTime.hpp"

namespace cme::mdp3::v13 {

namespace sbe = cme::mdp3::v13;

#pragma pack(push, 1)

// SnapshotFullRefreshOrderBook
struct SnapshotFullRefreshOrderBook {

    sbe::LastMsgSeqNumProcessed LastMsgSeqNumProcessed;
    sbe::TotNumReports TotNumReports;
    sbe::SecurityId SecurityId;
    sbe::NoChunks NoChunks;
    sbe::CurrentChunk CurrentChunk;
    sbe::TransactTime TransactTime;

    // parse method
    static SnapshotFullRefreshOrderBook* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshOrderBook*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshOrderBook* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshOrderBook*>(buffer);
    }
};

#pragma pack(pop)
}
