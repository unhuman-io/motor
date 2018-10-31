set(CMAKE_CXX_STANDARD 11)

add_subdirectory(hal_simulator)
add_subdirectory(system)

add_executable(motor_simulator main.cpp)
target_link_libraries(motor_simulator motor_base easylogging hal_simulator)
target_include_directories(motor_simulator PRIVATE ${CMAKE_BINARY_DIR}/3rdparty/easylogging ${CMAKE_SOURCE_DIR}/src/hal_simulator)