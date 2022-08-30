cmake_minimum_required(VERSION 3.23)
project(hash_table)

find_package(GTest REQUIRED)

add_executable(hash_table hashTable.h main.cpp)
target_link_libraries(hash_table PRIVATE GTest::gmock_main)
