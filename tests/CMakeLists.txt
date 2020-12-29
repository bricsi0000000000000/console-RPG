cmake_minimum_required(VERSION 3.10)

project(RPG-game)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unitTests unitTests.cpp) 
target_link_libraries(unitTests ${GTEST_LIBRARIES} pthread)