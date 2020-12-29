cmake_minimum_required(VERSION 2.6)

SET(CMAKE_CXX_FLAGS "-std=gnu++11") #Turn on C++11 Support

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(FILES_TO_TEST unitTests.cpp)
set(UNIT_TESTS unitTests.cpp)
set(MAIN_FILE unitTests.cpp)

add_library(codeToTest ${FILES_TO_TEST})

add_executable(rpg ${MAIN_FILE})
target_link_libraries(rpg codeToTest)

add_executable(unit-test ${UNIT_TESTS})
target_link_libraries(unit-test gtest gtest_main rt pthread codeToTest)