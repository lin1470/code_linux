cmake_minimum_required (VERSION 3.0)

project(io)

aux_source_directory(. DIR_SRCS)

add_subdirectory(../lib cassdk.out)

add_executable(io ./fgetsfputs.c)


target_link_libraries(io apue)
