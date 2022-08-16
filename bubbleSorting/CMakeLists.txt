cmake_minimum_required(VERSION 3.23)
project(bubbleSorting)

find_package(GTest REQUIRED)

add_executable(bubbleSorting main.cpp)
target_link_libraries(bubbleSorting PRIVATE GTest::gmock_main)
