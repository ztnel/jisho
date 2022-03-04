cmake_minimum_required(VERSION 3.16.x)
project(jisho-example)
# Add merase library
include(FetchContent)
message(STATUS "Fetching static dependancies")
FetchContent_Declare(
  merase
  GIT_REPOSITORY https://github.com/ztnel/merase
  GIT_TAG v0.1.5
)
FetchContent_MakeAvailable(merase)
message(STATUS "Building jisho example")
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/.. ${CMAKE_BINARY_DIR}/jisho)
include_directories(${JISHO_INCLUDE} ${MERASE_INCLUDE})
add_executable(jisho-ex main.c)
target_link_libraries(jisho-ex jisho-static)