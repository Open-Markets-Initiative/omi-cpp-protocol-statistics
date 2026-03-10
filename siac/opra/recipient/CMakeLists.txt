cmake_minimum_required(VERSION 3.28)

project(siac_opra_recipient_obi_v6_1_statistics)

set(CMAKE_CXX_STANDARD 23)

add_executable(siac_opra_recipient_obi_v6_1_statistics main.cpp)

find_package(ZLIB)
if(ZLIB_FOUND)
    target_compile_definitions(siac_opra_recipient_obi_v6_1_statistics PRIVATE HAS_ZLIB)
    target_link_libraries(siac_opra_recipient_obi_v6_1_statistics PRIVATE ZLIB::ZLIB)
endif()

find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(ZSTD IMPORTED_TARGET libzstd)
    if(ZSTD_FOUND)
        target_compile_definitions(siac_opra_recipient_obi_v6_1_statistics PRIVATE HAS_ZSTD)
        target_link_libraries(siac_opra_recipient_obi_v6_1_statistics PRIVATE PkgConfig::ZSTD)
    endif()
endif()