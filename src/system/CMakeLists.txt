add_subdirectory(control)

add_library(motor_base
            system_update_loop.cpp system_update_loop.h
            main_control_loop.cpp main_control_loop.h
            foc_control_loop.cpp foc_control_loop.h
            communication.cpp communication.h
            control/foc.cpp control/foc.h)
target_link_libraries(motor_base hal messages easylogging)
