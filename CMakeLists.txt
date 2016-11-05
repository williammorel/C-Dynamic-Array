cmake_minimum_required(VERSION 3.6)
project(test_lists)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        Main.c
        Functions.h
        Functions.c)

add_executable(test_lists ${SOURCE_FILES})