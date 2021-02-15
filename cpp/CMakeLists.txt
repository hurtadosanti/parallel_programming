cmake_minimum_required(VERSION 3.16)
project(parallel_programming)

set(CMAKE_CXX_STANDARD 17)
find_package(TBB REQUIRED tbb)

include_directories(. include)

file(GLOB recipes_SRC
        "recipes/*.cpp")

file(GLOB samples_SRC
        "samples/*.cpp")

add_library(${PROJECT_NAME}_recipes ${recipes_SRC})
target_link_libraries(${PROJECT_NAME}_recipes pthread)

add_library(${PROJECT_NAME}_samples ${samples_SRC}
        include/parallel_math.h
        include/serial_math.h
        )

target_link_libraries(${PROJECT_NAME}_samples pthread ${TBB_IMPORTED_TARGETS})

add_executable(matrix_multiply samples/matrix_multiply.cpp)
target_link_libraries(matrix_multiply pthread)
install(TARGETS matrix_multiply DESTINATION ${PROJECT_NAME})



add_executable(parallel_order recipes/parallel_ordering.cpp)
target_link_libraries(parallel_order pthread  ${TBB_IMPORTED_TARGETS})

add_executable(parallel_for_recipe recipes/parallel_for_recipe.cpp)
target_link_libraries(parallel_for_recipe pthread  ${TBB_IMPORTED_TARGETS})


add_subdirectory(tests)
enable_testing()


set(CPACK_GENERATOR "TGZ")
set(CPACP_DEBIAN_PACKAGE_MAINTAINER "Santiago Hurtado")

include(CPack)


