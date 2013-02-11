cmake_minimum_required(VERSION 2.8)
project(vitamine CXX)

set(CMAKE_CXX_COMPILER "/usr/local/bin/g++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)
