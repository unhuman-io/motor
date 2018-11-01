add_library(simulator system.cpp system.h)
target_link_libraries(simulator hal_simulator system easylogging)
target_include_directories(simulator PUBLIC .)