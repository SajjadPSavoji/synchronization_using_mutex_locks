
cmake_minimum_required(VERSION 2.8)

#set (CMAKE_CXX_COMPILER "/usr/bin/g++")
project(p3)

set (CMAKE_CXX_STANDARD 11)

set (GCC_COVERAGE_COMPILE_FLAGS "-pthread -lrt")
set (GCC_COVERAGE_LINK_FLAGS    "-pthread -lrt")

set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set (CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

include_directories(
    "include")

file (GLOB SOURCES
    "src/*.cpp"
    "include/*.hpp")

add_executable(${PROJECT_NAME}
    ${SOURCES})