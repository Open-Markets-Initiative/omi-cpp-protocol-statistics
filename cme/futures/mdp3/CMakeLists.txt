cmake_minimum_required(VERSION 3.28)

project(cme_futures_mdp3_sbe_v1_13_statistics)

set(CMAKE_CXX_STANDARD 23)

add_executable(cme_futures_mdp3_sbe_v1_13_statistics main.cpp)

find_package(ZLIB)
if(ZLIB_FOUND)
    target_compile_definitions(cme_futures_mdp3_sbe_v1_13_statistics PRIVATE HAS_ZLIB)
    target_link_libraries(cme_futures_mdp3_sbe_v1_13_statistics PRIVATE ZLIB::ZLIB)
endif()

find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_check_modules(ZSTD IMPORTED_TARGET libzstd)
    if(ZSTD_FOUND)
        target_compile_definitions(cme_futures_mdp3_sbe_v1_13_statistics PRIVATE HAS_ZSTD)
        target_link_libraries(cme_futures_mdp3_sbe_v1_13_statistics PRIVATE PkgConfig::ZSTD)
    endif()
endif()