cmake_minimum_required(VERSION 3.23)
project(postfix)

find_package(GTest REQUIRED)

add_executable(postfix main.cpp)
target_link_libraries(postfix PRIVATE GTest::gmock_main)
