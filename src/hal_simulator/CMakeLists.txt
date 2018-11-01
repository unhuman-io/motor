add_library(hal_simulator hal_fun.cpp motor_simulator.cpp motor_simulator.h
                          motor_simulator_voltage.cpp motor_simulator_voltage.h
                          hal_pwm.cpp
                          dq_transform.cpp dq_transform.h
                          periodic_loop.cpp)
target_link_libraries(hal_simulator hal easylogging pthread)
target_include_directories(hal_simulator PUBLIC .)