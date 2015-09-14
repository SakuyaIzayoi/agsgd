cmake_minimum_required (VERSION 2.8)
project (Agsgd)

set(Agsgd_VERSION_MAJOR 0)
set(Agsgd_VERSION_MINOR 1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

FILE(GLOB MEM_SRCFILES ${PROJECT_SOURCE_DIR}/src/engine/memory/*.cpp)
FILE(GLOB CONTAINERS_SRCFILES ${PROJECT_SOURCE_DIR}/src/engine/containers/*.cpp)

FILE(GLOB TEST_MAIN ${PROJECT_SOURCE_DIR}/src/test/test.cpp)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories($(PROJECT_SOURCE_DIR)/src)
include_directories($(PROJECT_SOURCE_DIR)/src/engine/memory)
include_directories($(PROJECT_SOURCE_DIR)/src/engine/containers)

add_executable (Agsgd game.m.cpp)
add_executable(agsgd_test ${TEST_MAIN} ${MEM_SRCFILES} ${CONTAINERS_SRCFILES})

target_link_libraries(agsgd_test ${GTEST_BOTH_LIBRARIES})
target_link_libraries(agsgd_test "${CMAKE_THREAD_LIBS_INIT}")
