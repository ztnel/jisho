cmake_minimum_required(VERSION 3.16.x)
project(jisho-example)

message(STATUS "Building jisho example")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_BINARY_DIR}/jisho)
include_directories(${JISHO_INCLUDE})
add_executable(jisho-ex main.c)
target_link_libraries(jisho-ex jisho-static)