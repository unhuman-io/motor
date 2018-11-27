#include <stdint.h>

struct HardwareParam {
		uint8_t led_gpio_num;
};

void pin_init(HardwareParam * const);
