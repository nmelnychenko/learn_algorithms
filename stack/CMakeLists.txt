cmake_minimum_required(VERSION 3.23)
project(stack)

find_package(GTest REQUIRED)

add_executable(stack stack.h main.cpp)
target_link_libraries(stack PRIVATE GTest::gmock_main)
