cmake_minimum_required(VERSION 3.16)
project(cuda_sort CXX CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_subdirectory(tests)
include_directories(. include)

add_library(${PROJECT_NAME} Sorting.cu)
set_target_properties(${PROJECT_NAME}  PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
enable_testing()