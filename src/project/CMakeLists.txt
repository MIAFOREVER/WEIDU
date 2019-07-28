cmake_minimum_required(VERSION 3.0)

project(server)

include_directories(
    inc
    ../Tools
    ../Log/inc
    ../Praser/inc
    ../HttpServer/inc
)
set(server  
    ../HttpServer/src/HttpServer.cpp
    ../Tools/json.hpp
    ../Log/src/Log.cpp
    ../Praser/src/Praser.cpp
    ../HttpServer/src/status.cpp
    server.cpp
)
add_executable(server ${server})
target_link_libraries(server -pthread)
