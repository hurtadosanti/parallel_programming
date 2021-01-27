cmake_minimum_required(VERSION 3.16)
project(ParallelProgramming)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread)

add_executable(scheduling_demo scheduling_demo.cpp)
target_link_libraries(scheduling_demo pthread)

add_executable(monitor monitor.cpp)
target_link_libraries(monitor pthread)

add_executable(producer_consumer producer_consumer.cpp)
target_link_libraries(producer_consumer pthread)

add_executable(data_race data_race.cpp)
target_link_libraries(data_race pthread)
#gcc-11
#add_executable(ping_pong_semaphore ping_pong_semaphore.cpp)
#target_link_libraries(ping_pong_semaphore pthread)

add_executable(atomic_object atomic_object.cpp)
target_link_libraries(atomic_object pthread)

add_executable(recursive_mutex recursive_mutex.cpp)
target_link_libraries(recursive_mutex pthread)