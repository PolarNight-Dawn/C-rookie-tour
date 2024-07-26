cmake_minimum_required(VERSION 3.27)
project(C__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Multi 技巧篇/multi_type_return_value.cpp)

find_package(Threads REQUIRED)
add_executable(Thread The_Cherno/技巧篇/thread.cpp)
target_link_libraries(Thread Threads::Threads)