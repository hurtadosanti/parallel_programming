cmake_minimum_required(VERSION 3.15)
project(tests)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(benchmark REQUIRED)

add_executable(benchmark_samples benchmark_samples.cpp)
target_link_libraries(benchmark_samples benchmark::benchmark parallel_programming_samples)

add_executable(test_samples test_samples.cpp)
target_link_libraries(test_samples ${GTEST_LIBRARIES} pthread parallel_programming_samples)