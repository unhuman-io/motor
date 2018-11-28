add_executable(st446 main.cpp pin_init.cpp pin_init.h
                     system_init.cpp system_init.h
                     stm32f446xx_local.h
                     stdout_USART.c)
target_link_libraries(st446 hal_m4 system cmsis)