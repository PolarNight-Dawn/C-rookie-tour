cmake_minimum_required(VERSION 3.27)
project(The_Cherno)

add_executable(Multi 技巧篇/multi_type_return_value.cpp)

find_package(Threads REQUIRED)
add_executable(Thread 技巧篇/thread.cpp)
target_link_libraries(Thread Threads::Threads)

add_executable(Benchmaking 技巧篇/benchmaking.cpp)
add_executable(Memory 技巧篇/memory_allocate.cpp)