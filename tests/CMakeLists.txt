cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)

add_executable( runUnitTests unitTests.cpp )
target_link_libraries(runUnitTests gtest gtest_main pthread)

add_test(AllUnitTests runUnitTests)