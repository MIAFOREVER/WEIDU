cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0048 NEW)
project(my_gtest_pkgconfig VERSION 0.0.1 LANGUAGES CXX)

find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)

include_directories(
    inc
    ../Log/inc
    ../Praser/inc
    ../Tools
)
set(HttpServerTest
    test/HttpServerTest.cpp 
    src/HttpServer.cpp 
    ../Praser/src/Praser.cpp
    ../Log/src/Log.cpp
)

add_executable(HttpServerTest ${HttpServerTest} )
target_link_libraries(HttpServerTest ${GTEST_LDFLAGS} -pthread)
target_compile_options(HttpServerTest PUBLIC ${GTEST_CFLAGS})

include(CTest)
add_test(first_and_only_test HttpServerTest)