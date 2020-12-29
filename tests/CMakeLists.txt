include(gtest)
enable_testing()
set(console_RPG_test ${PROJECT_NAME}_test)
include_directories(${GTEST_INCLUDE_DIRS})

  file(GLOB_RECURSE TEST_SRC_FILES RELATIVE
       ${PROJECT_SOURCE_DIR}
       *.cpp)
message(STATUS "Test case source files: " ${TEST_SRC_FILES})

add_executable(${console_RPG_test} ${TEST_SRC_FILES})

add_dependencies(${console_RPG_test} ${PROJECT_NAME})