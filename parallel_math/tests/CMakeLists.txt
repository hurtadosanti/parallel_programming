cmake_minimum_required(VERSION 3.10)
project(perf_math_tests)
set(CMAKE_CXX_STANDARD 14)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# ----------  Multithread Unit Tests  -------
add_executable(multithread_natural_numbers_tests multithread_natural_numbers_tests.cpp)
target_link_libraries(multithread_natural_numbers_tests
        ${GTEST_LIBRARIES} pthread
        perf_multithread_math_lib)

add_test(
        NAME multithread_natural_numbers_tests
        COMMAND $<TARGET_FILE:multithread_natural_numbers_tests>
)

add_executable(multithread_vector_tests multithread_vector_tests.cpp)
target_link_libraries(multithread_vector_tests
        ${GTEST_LIBRARIES} pthread
        perf_multithread_math_lib)
add_test(
        NAME multithread_vector_tests
        COMMAND $<TARGET_FILE:multithread_vector_tests>
)

add_test(
        NAME
        multithread_math_python_test
        COMMAND
        ${CMAKE_COMMAND} -E env PARALLEL_MATH_MODULE_PATH=$<TARGET_FILE_DIR:multithread_math>
        ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/multithread_math_test.py
)

# ----------  Parallel Unit Tests  -------
add_executable(parallel_natural_numbers_tests parallel_natural_numbers_tests.cpp)
target_link_libraries(parallel_natural_numbers_tests
        ${GTEST_LIBRARIES} pthread
        perf_vector_math_lib perf_multithread_math_lib)
add_test(
        NAME parallel_natural_numbers_tests
        COMMAND $<TARGET_FILE:parallel_natural_numbers_tests>
)

add_executable(parallel_vector_tests parallel_vector_tests.cpp)
target_link_libraries(parallel_vector_tests
        ${GTEST_LIBRARIES} pthread
        perf_vector_math_lib)

add_test(
        NAME parallel_vector_tests
        COMMAND $<TARGET_FILE:parallel_vector_tests>
)

add_test(
        NAME
        parallel_math_python_test
        COMMAND
        ${CMAKE_COMMAND} -E env PARALLEL_MATH_MODULE_PATH=$<TARGET_FILE_DIR:parallel_math>
        ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/parallel_math_test.py
)
enable_testing()

