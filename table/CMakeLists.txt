cmake_minimum_required(VERSION 3.23)
project(table)

find_package(GTest REQUIRED)

add_executable(table table.h main.cpp)
target_link_libraries(table PRIVATE GTest::gmock_main)
