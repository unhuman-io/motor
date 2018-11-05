#add_subdirectory(control)

add_library(system
            system_update_loop.cpp system_update_loop.h
            main_control_loop.cpp main_control_loop.h
            foc_control_loop.cpp foc_control_loop.h
            communication.cpp communication.h
            control/foc.cpp control/foc.h
            control/control_fun.cpp control/control_fun.h
            system.cpp system.h
            sensor/encoder.cpp sensor/encoder.h
            sensor/qep_encoder.cpp sensor/qep_encoder.h
            sensor/sensor.cpp sensor/sensor.h)
target_link_libraries(system hal messages easylogging)
target_include_directories(system PUBLIC . control/)
