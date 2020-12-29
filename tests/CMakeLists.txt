cmake_minimum_required(VERSION 3.10)

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

# Add test cpp file
add_executable(runUnitTests unitTests.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests ${GTEST_LIBRARY_DEBUG} ${GTEST_MAIN_LIBRARY_DEBUG})

add_test(
    NAME runUnitTests
    COMMAND runUnitTests
)