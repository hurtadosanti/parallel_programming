cmake_minimum_required(VERSION 3.10)

# C++ Code
project(perf_multithread_math_lib CXX)
set(CMAKE_CXX_STANDARD 14)
option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" ON)

add_library(perf_multithread_math_lib multithread/NaturalNumbers.cpp multithread/Vectors.cpp)
target_link_libraries(perf_multithread_math_lib pthread)

#Boost Python
project(parallel_math CXX)
find_package(Boost 1.70.0 COMPONENTS thread python REQUIRED)
find_package(PythonInterp REQUIRED)
find_package(PythonLibs 3.6 REQUIRED)

include_directories(${BOOST_INCLUDE_DIRS})

# multithread lib boost python
add_library(multithread_math SHARED python/multithread_math.cpp)
target_link_libraries(multithread_math Boost::python perf_multithread_math_lib)
target_include_directories(multithread_math PRIVATE ${PYTHON_INCLUDE_DIRS})

set_target_properties(multithread_math PROPERTIES PREFIX "")


# Cuda Code
project(perf_vector_math_lib CUDA)
set(CMAKE_CUDA_STANDARD 14)
add_library(perf_vector_math_lib parallel/NaturalNumbers.cu parallel/Vectors.cu )
set_target_properties(perf_vector_math_lib PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

# parallel lib  python
add_library(parallel_math SHARED python/parallel_math.cpp)
target_link_libraries(parallel_math Boost::python perf_vector_math_lib)
target_include_directories(parallel_math PRIVATE ${PYTHON_INCLUDE_DIRS})

set_target_properties(parallel_math PROPERTIES PREFIX "")
