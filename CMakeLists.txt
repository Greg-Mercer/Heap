cmake_minimum_required(VERSION 3.12)
project(Heap)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

add_executable(Heap main.cpp heap.hpp)