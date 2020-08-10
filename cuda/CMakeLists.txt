cmake_minimum_required(VERSION 3.10)
project(parallel_math CXX CUDA)
set(CMAKE_CUDA_STANDARD 14)
find_package(CUDA)

cuda_select_nvcc_arch_flags(ARCH_FLAGS "Auto")

list(APPEND CUDA_NVCC_FLAGS ${ARCH_FLAGS})

add_executable(${PROJECT_NAME} primes_sum.cu)

set_target_properties(${PROJECT_NAME} PROPERTIES CUDA_SEPARABLE_COMPILATION ON)