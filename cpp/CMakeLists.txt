cmake_minimum_required(VERSION 3.16)
project(parallel_programming)

set(CMAKE_CXX_STANDARD 20)

file(GLOB recipes_SRC
        "recipes/*.cpp")

file(GLOB samples_SRC
        "samples/*.cpp")

add_library(${PROJECT_NAME}_recipes ${recipes_SRC})
target_link_libraries(${PROJECT_NAME}_recipes pthread)

add_library(${PROJECT_NAME}_samples ${samples_SRC})
target_link_libraries(${PROJECT_NAME}_samples pthread)

add_subdirectory(tests)
enable_testing()