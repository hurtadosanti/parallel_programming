cmake_minimum_required(VERSION 3.15)
project(tests)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
find_package(TBB REQUIRED tbb)

include_directories(${GTEST_INCLUDE_DIRS})

find_package(benchmark REQUIRED)

add_executable(benchmark_samples benchmark_samples.cpp)
target_link_libraries(benchmark_samples benchmark::benchmark parallel_programming_samples)

add_executable(benchmark_recipes benchmark_recipes.cpp)
target_link_libraries(benchmark_recipes benchmark::benchmark ${TBB_IMPORTED_TARGETS})

add_executable(test_samples test_samples.cpp)
target_link_libraries(test_samples ${GTEST_LIBRARIES} pthread parallel_programming_samples)
add_test(
        NAME test_samples
        COMMAND $<TARGET_FILE:test_samples>
)

add_executable(test_recipes test_recipes.cpp)
target_link_libraries(test_recipes ${GTEST_LIBRARIES} pthread parallel_programming_recipes)
add_test(
        NAME test_recipes
        COMMAND $<TARGET_FILE:test_recipes>
)

install(TARGETS benchmark_samples DESTINATION parallel_programming/tests)

install(TARGETS test_samples DESTINATION parallel_programming/tests)
install(TARGETS test_recipes DESTINATION parallel_programming/tests)

include(CPack)
enable_testing()