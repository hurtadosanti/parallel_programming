cmake_minimum_required(VERSION 3.15)
project(tests)

find_package(benchmark REQUIRED)
add_executable(benchmark_samples benchmark_samples.cpp)
target_link_libraries(benchmark_samples benchmark::benchmark parallel_programming_samples)