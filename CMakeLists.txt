cmake_minimum_required(VERSION 3.12)
project(motor)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS OFF)

add_subdirectory(3rdparty)
add_subdirectory(src)
add_subdirectory(sdk)