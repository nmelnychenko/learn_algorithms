cmake_minimum_required(VERSION 3.23)
project(quickSorting)

find_package(GTest REQUIRED)

add_executable(quickSorting main.cpp)
target_link_libraries(quickSorting PRIVATE GTest::gmock_main)
