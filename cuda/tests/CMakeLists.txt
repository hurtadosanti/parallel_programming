cmake_minimum_required(VERSION 3.15)
project(tests CXX CUDA)
set(CMAKE_CUDA_STANDARD 14)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

add_executable(benchmark_cuda benchmark_cuda.cu)
target_link_libraries(benchmark_cuda benchmark::benchmark cuda_sort)
set_target_properties(benchmark_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

enable_testing()