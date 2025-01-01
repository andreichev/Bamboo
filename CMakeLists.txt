cmake_minimum_required(VERSION 3.16)

project(Bamboo)

set(CMAKE_CXX_STANDARD 20)
set(BAMBOO_BIN_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-DPROFILE)
endif ()

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE INCLUDE include/*.hpp)

add_library(Bamboo STATIC "${SOURCES}" Bamboo.def "${INCLUDE}")

set_target_properties(Bamboo
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${BAMBOO_BIN_DIRECTORY}
)

target_include_directories(Bamboo PRIVATE ${PROJECT_SOURCE_DIR}/src)
target_include_directories(Bamboo PUBLIC ${PROJECT_SOURCE_DIR}/include)

