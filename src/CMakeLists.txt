set(CMAKE_CXX_STANDARD 11)
add_compile_definitions(ELPP_THREAD_SAFE ELPP_FORCE_USE_STD_THREAD)

add_subdirectory(messages)
add_subdirectory(hal)
add_subdirectory(hal_simulator)
add_subdirectory(hal_m4)
add_subdirectory(system)
add_subdirectory(simulator)
add_subdirectory(api)

add_executable(motor_simulator main_simulator.cpp)
target_link_libraries(motor_simulator PRIVATE simulator system easylogging hal_simulator )

#TODO: motor_m4 will be the version for Cortex M4
#add_executable(motor_m4 main_simulator.cpp)
#target_link_libraries(motor_m4 PRIVATE motor_base easylogging hal_m4)
