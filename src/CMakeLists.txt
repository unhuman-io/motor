set(CMAKE_CXX_STANDARD 11)

add_subdirectory(messages)
add_subdirectory(hal)
add_subdirectory(system)
if(MCU_ARCH STREQUAL cortex-m4)
    add_subdirectory(hal_m4)
   # add_executable(main_m4 "")
#    target_link_libraries(main_m4 PRIVATE hal_m4 st446)
else()
    add_subdirectory(hal_simulator)
    add_subdirectory(simulator)
    add_subdirectory(api)

    add_executable(main_simulator main_simulator.cpp)
    target_link_libraries(main_simulator PRIVATE cpp_api easylogging)
endif()



#TODO: motor_m4 will be the version for Cortex M4
#add_executable(motor_m4 main_simulator.cpp)
#target_link_libraries(motor_m4 PRIVATE motor_base easylogging hal_m4)
