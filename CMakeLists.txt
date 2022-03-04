cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(
    jisho
    LANGUAGES C
    VERSION "0.0.1"
    DESCRIPTION "Simple hash table api."
)

set(CMAKE_C_STANDARD 99)

if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR 
        "In source builds not allowed. Create a build directory and run cmake from there"
    )
endif()

# Detect if the project is being build within a project or standalone.
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(STANDALONE true)
else()
  set(STANDALONE false)
endif()

if (NOT ${STANDALONE})
  set(JISHO_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)
endif()

# Add merase library
include(FetchContent)
message(STATUS "Fetching static dependancies")
FetchContent_Declare(
  merase
  GIT_REPOSITORY https://github.com/ztnel/merase
  GIT_TAG v0.1.6
)
FetchContent_MakeAvailable(merase)

set(
    JISHO_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jisho.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prime.c
)

set(
    JISHO_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(jisho-static STATIC ${JISHO_SRC})
include_directories(${MERASE_INCLUDE})
target_link_libraries(jisho-static PRIVATE merase-static)
target_include_directories(jisho-static PRIVATE ${JISHO_INCLUDE})
target_compile_options(jisho-static PRIVATE -Wall)
