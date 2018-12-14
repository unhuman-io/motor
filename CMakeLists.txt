cmake_minimum_required(VERSION 3.12)
project(motor)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(BUILD_SHARED_LIBS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(WIN32)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /FI win32.h")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FI win32.h")
include_directories(src/win32)
endif()

add_subdirectory(3rdparty)
add_subdirectory(src)
add_subdirectory(sdk)