cmake_minimum_required(VERSION 3.10)

project(Dijkstra2)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.h"
)

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})