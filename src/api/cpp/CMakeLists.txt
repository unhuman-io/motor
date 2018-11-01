add_library(cpp_api motor.cpp motor.h
                            motor_simulator.cpp motor_simulator.h)
target_include_directories(cpp_api PUBLIC .)
target_link_libraries(cpp_api messages system simulator)
install(FILES motor.h motor_simulator.h DESTINATION sdk/cpp/include)
install(TARGETS cpp_api DESTINATION sdk/cpp)