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

set(
    JISHO_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/jisho.c)
    ${CMAKE_CURRENT_SOURCE_DIR}/src/prime.c
)

set(
    JISHO_INCLUDE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(jisho-static STATIC ${JISHO_SRC})
target_include_directories(jisho-static PRIVATE ${MERASE_INCLUDE})
target_compile_options(jisho-static PRIVATE -Wall)
