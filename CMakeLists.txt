cmake_minimum_required (VERSION 3.22)

SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_C_COMPILER gcc)

project (Agsgd)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(Agsgd_VERSION_MAJOR 0)
set(Agsgd_VERSION_MINOR 1)

find_package(Threads REQUIRED)

configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if(result)
	message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	RESULT_VARIABLE result
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if(result)
	message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
				 ${CMAKE_BINARY_DIR}/googletest-build
				 EXCLUDE_FROM_ALL)

if (CMAKE_VERSION VERSION_LESS 2.8.11)
	include_directories("${gtest_SOURCE_DIR}/include")
endif()

SET(CMAKE_CXX_FLAGS "-std=c++11")

FILE(GLOB MEM_SRCFILES ${PROJECT_SOURCE_DIR}/src/engine/memory/*.cpp)
FILE(GLOB CONTAINERS_SRCFILES ${PROJECT_SOURCE_DIR}/src/engine/containers/*.cpp)
FILE(GLOB SCENE_SRCFILES ${PROJECT_SOURCE_DIR}/src/engine/scene)

FILE(GLOB TEST_MAIN ${PROJECT_SOURCE_DIR}/src/test/test.cpp)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/engine/memory)
include_directories(${PROJECT_SOURCE_DIR}/src/engine/containers)
include_directories(${PROJECT_SOURCE_DIR}/src/engine/scene)

add_executable(engine game.m.cpp)
add_executable(agsgd_test ${TEST_MAIN} ${MEM_SRCFILES} ${CONTAINERS_SRCFILES})

target_link_libraries(agsgd_test gtest_main)
target_link_libraries(agsgd_test "${CMAKE_THREAD_LIBS_INIT}")

