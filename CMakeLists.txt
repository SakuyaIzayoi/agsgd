cmake_minimum_required (VERSION 2.8)
project (Agsgd)

set(Agsgd_VERSION_MAJOR 0)
set(Agsgd_VERSION_MINOR 1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories($(PROJECT_SOURCE_DIR)/src)

add_executable (Agsgd game.m.cpp)
add_executable(agsgd_test ${PROJECT_SOURCE_DIR}/src/test/test.cpp)

target_link_libraries(agsgd_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(agsgd_test "${CMAKE_THREAD_LIBS_INIT}")
