cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0048 NEW)
project(my_gtest_pkgconfig VERSION 0.0.1 LANGUAGES CXX)

find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)

include_directories(
    inc
    ../Tools
    ../Log/inc
)
set(PraserTest 
    test/PraserTest.cpp 
    src/Praser.cpp
    ../Tools/json.hpp
    ../Log/src/Log.cpp
)
add_executable(PraserTest ${PraserTest})
target_link_libraries(PraserTest ${GTEST_LDFLAGS})
target_compile_options(PraserTest PUBLIC ${GTEST_CFLAGS})

include(CTest)
add_test(first_and_only_test PraserTest)