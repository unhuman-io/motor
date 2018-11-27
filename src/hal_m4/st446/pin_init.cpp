
#include "pin_init.h"
#include "stm32f446xx_local.h"

void pin_init(HardwareParam * const hw_param) {
	RCC->AHB1ENR |=  (1ul << 0);                  /* Enable GPIOA clock         */

  /* Configure LED (PA.5) pins as push-pull outputs, No pull-up, pull-down */
  GPIOA->MODER   &= ~((3ul << 2*5));
  GPIOA->MODER   |=  ((1ul << 2*5));
  GPIOA->OTYPER  &= ~((1ul <<   5));
  GPIOA->OSPEEDR &= ~((3ul << 2*5));
  GPIOA->OSPEEDR |=  ((1ul << 2*5));
  GPIOA->PUPDR   &= ~((3ul << 2*5));
	GPIOA->BSRR |= (1 << 5);
	hw_param->led_gpio_num = 5;
}
