cmake_minimum_required(VERSION 3.28)

project(iex_equities_deepplus_iextp_v1_0_1_statistics)

set(CMAKE_CXX_STANDARD 23)

add_executable(iex_equities_deepplus_iextp_v1_0_1_statistics main.cpp)

# Shared pcap infrastructure headers at repo root
target_include_directories(iex_equities_deepplus_iextp_v1_0_1_statistics PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/packet)

find_package(ZLIB)
if(ZLIB_FOUND)
    target_compile_definitions(iex_equities_deepplus_iextp_v1_0_1_statistics PRIVATE HAS_ZLIB)
    target_link_libraries(iex_equities_deepplus_iextp_v1_0_1_statistics PRIVATE ZLIB::ZLIB)
endif()

find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(ZSTD IMPORTED_TARGET libzstd)
    if(ZSTD_FOUND)
        target_compile_definitions(iex_equities_deepplus_iextp_v1_0_1_statistics PRIVATE HAS_ZSTD)
        target_link_libraries(iex_equities_deepplus_iextp_v1_0_1_statistics PRIVATE PkgConfig::ZSTD)
    endif()
endif()