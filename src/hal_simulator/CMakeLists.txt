add_library(hal_simulator hal_fun.cpp ../hal/hal_fun.h)
target_link_libraries(hal_simulator easylogging)
target_include_directories(hal_simulator PRIVATE ${CMAKE_BINARY_DIR}/3rdparty/easylogging)