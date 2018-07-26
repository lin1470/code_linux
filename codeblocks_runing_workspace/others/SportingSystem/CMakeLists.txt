cmake_minimum_required(VERSION 3.6)
project(SportingSystem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES  main.c menu.c data.h itemFile.c test.c itemEdit.c itemManage.c tools.c itemControl.c)
add_executable(SportingSystem ${SOURCE_FILES})

