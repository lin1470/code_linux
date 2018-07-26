cmake_minimum_required(VERSION 3.10)
project(socket2)

set(CMAKE_CXX_STANDARD 11)
link_libraries(ws2_32)

add_executable(socket2 main.cpp)