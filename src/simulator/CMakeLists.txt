add_library(simulator motor_simulator.cpp motor_simulator.h
        motor_simulator_voltage.cpp motor_simulator_voltage.h)
target_link_libraries(simulator hal_simulator system easylogging)
target_include_directories(simulator PUBLIC .)