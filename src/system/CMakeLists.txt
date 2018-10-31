add_library(motor_base
            system_update_loop.cpp system_update_loop.h
            periodic_loop.cpp periodic_loop.h
            main_control_loop.cpp main_control_loop.h
            foc_control_loop.cpp foc_control_loop.h
            communication.cpp communication.h)
target_link_libraries(motor_base easylogging)
target_include_directories(motor_base PRIVATE ${CMAKE_BINARY_DIR}/3rdparty/easylogging)
