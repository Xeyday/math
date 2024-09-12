cmake_minimum_required(VERSION 3.22)

project(xeyday.math
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(XEYDAY_MATH_DEPENDENCIES_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dependencies")
set(XEYDAY_MATH_DEPENDENCIES_INCLUDE_DIR "${XEYDAY_MATH_DEPENDENCIES_DIR}/include")

add_subdirectory(src)
add_subdirectory(testing)
