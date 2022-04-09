cmake_minimum_required(VERSION 3.21)
project(practice_myself)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(practice_myself
        MergeSort/main.cpp
        func.h MergeSort/Classic_mergeSort.cpp)
