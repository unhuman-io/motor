add_library(simulator simulator.cpp simulator.h
        brushless_motor_simulation.cpp brushless_motor_simulation.h)
target_link_libraries(simulator hal_simulator system easylogging)
target_include_directories(simulator PUBLIC .)