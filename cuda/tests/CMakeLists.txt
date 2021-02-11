cmake_minimum_required(VERSION 3.15)
project(tests)
set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)