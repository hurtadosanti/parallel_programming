cmake_minimum_required(VERSION 3.10)
project(perf_math)

set(CMAKE_CXX_STANDARD 14)
include_directories(. include)

add_subdirectory(src)
add_subdirectory(tests)
add_executable(perf_math main.cpp)

enable_testing()