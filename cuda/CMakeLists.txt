cmake_minimum_required(VERSION 3.16)
project(cuda CXX CUDA)

set(CMAKE_CUDA_STANDARD 14)

add_executable(${PROJECT_NAME} main.cu Sorting.h Sorting.cu)

set_target_properties(cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)