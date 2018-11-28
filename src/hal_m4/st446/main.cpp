#include "system_init.h"
#include "stm32f446xx_local.h"
#include "pin_init.h"
#include <cstdio>

extern "C" {
extern int stdout_init (void);
}

static int32_t ms_ticks = 0;

int main (void) {
	system_clock_init();
	HardwareParam hw_param;
	pin_init(&hw_param);
	SysTick_Config(180000000 / 1000);
	stdout_init();    
	int32_t target_ms_time = 1000;
	while(1) {
		while(ms_ticks < target_ms_time);
		std::printf("Hello World %ld\n\r", ms_ticks);
		target_ms_time += 1000;
		GPIOA->ODR ^= (1 << hw_param.led_gpio_num);
	}
}

extern "C" {
void SysTick_Handler(void) {
	ms_ticks++;
}
}
