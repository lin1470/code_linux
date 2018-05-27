cmake_minimum_required(VERSION 3.9)
project(tcp)

set(CMAKE_CXX_STANDARD 11)

add_executable(tcp main.cpp tcpserver.cpp tcpclient.cpp)