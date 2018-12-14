add_library(hal_m4 STATIC hal_fun.cpp periodic_loop.cpp)
target_link_libraries(hal_m4 hal easylogging)

add_subdirectory(st446)