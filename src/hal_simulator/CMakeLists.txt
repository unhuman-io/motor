add_library(hal_simulator hal_fun.cpp
                          hal_pwm.cpp
                          hal_adc.cpp
                          dq_transform.cpp dq_transform.h
                          periodic_loop.cpp)
target_link_libraries(hal_simulator hal easylogging pthread messages)
target_include_directories(hal_simulator PUBLIC .)