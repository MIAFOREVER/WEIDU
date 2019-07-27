cmake_minimum_required(VERSION 3.0)

cmake_policy(SET CMP0048 NEW)
project(my_gtest_pkgconfig VERSION 0.0.1 LANGUAGES CXX)

find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)

include_directories(
    inc
    ../Log/inc
    ../Tools
)
set(FileSystemTest
    test/FileSystemTest.cpp 
    src/FileSystem.cpp 
    ../Log/src/Log.cpp
)

add_executable(FileSystemTest ${FileSystemTest} )
target_link_libraries(FileSystemTest ${GTEST_LDFLAGS})
target_compile_options(FileSystemTest PUBLIC ${GTEST_CFLAGS})

include(CTest)
add_test(first_and_only_test FileSystemTest)