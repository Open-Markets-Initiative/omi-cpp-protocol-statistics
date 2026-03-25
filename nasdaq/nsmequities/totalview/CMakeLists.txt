cmake_minimum_required(VERSION 3.28)

project(nasdaq_nsmequities_totalview_itch_v5_0_statistics)

set(CMAKE_CXX_STANDARD 23)

add_executable(nasdaq_nsmequities_totalview_itch_v5_0_statistics main.cpp)

# Shared pcap infrastructure headers at repo root
target_include_directories(nasdaq_nsmequities_totalview_itch_v5_0_statistics PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/packet)

find_package(ZLIB)
if(ZLIB_FOUND)
    target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_statistics PRIVATE HAS_ZLIB)
    target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_statistics PRIVATE ZLIB::ZLIB)
endif()

find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(ZSTD IMPORTED_TARGET libzstd)
    if(ZSTD_FOUND)
        target_compile_definitions(nasdaq_nsmequities_totalview_itch_v5_0_statistics PRIVATE HAS_ZSTD)
        target_link_libraries(nasdaq_nsmequities_totalview_itch_v5_0_statistics PRIVATE PkgConfig::ZSTD)
    endif()
endif()