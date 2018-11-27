#include "stm32f4xx.h" 

void system_clock_init() {
  RCC->CR |= ((uint32_t)RCC_CR_HSION);                     /* Enable HSI */
  while ((RCC->CR & RCC_CR_HSIRDY) == 0);                  /* Wait for HSI Ready */

  RCC->CFGR = RCC_CFGR_SW_HSI;                             /* HSI is system clock */
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_HSI);  /* Wait for HSI used as system clock */

  FLASH->ACR  = (FLASH_ACR_PRFTEN     |                    /* Enable Prefetch Buffer */
                 FLASH_ACR_ICEN       |                    /* Instruction cache enable */
                 FLASH_ACR_DCEN       |                    /* Data cache enable */
                 FLASH_ACR_LATENCY_5WS );                  /* Flash 5 wait state */

  RCC->CFGR |= (RCC_CFGR_HPRE_DIV1  |                      /* HCLK = SYSCLK */
                RCC_CFGR_PPRE1_DIV4 |                      /* APB1 = HCLK/4 */
                RCC_CFGR_PPRE2_DIV2  );                    /* APB2 = HCLK/2 */

  RCC->CR &= ~RCC_CR_PLLON;                                /* Disable PLL */

  /* PLL configuration:  VCO = HSI/M * N,  Sysclk = VCO/P */
	// SystemCoreClock = ((INPUT_CLOCK (HSE_OR_HSI_IN_HZ) / PLL_M) * PLL_N) / PLL_P
  RCC->PLLCFGR = (( 16ul << RCC_PLLCFGR_PLLM_Pos) |                /* PLL_M =  16 */
                  (360ul << RCC_PLLCFGR_PLLN_Pos) |                /* PLL_N = 360 */
                  (  0ul << RCC_PLLCFGR_PLLP_Pos) |                /* PLL_P =   2 */
                  (RCC_PLLCFGR_PLLSRC_HSI)        |                /* PLL_SRC = HSI */
                  (  7ul << RCC_PLLCFGR_PLLQ_Pos) |                /* PLL_Q =   7 */
                  (  2ul << RCC_PLLCFGR_PLLR_Pos));              	 /* PLL_R =   2 */

  RCC->CR |= RCC_CR_PLLON;                                 /* Enable PLL */
  while((RCC->CR & RCC_CR_PLLRDY) == 0) __NOP();           /* Wait till PLL is ready */

  RCC->CFGR &= ~RCC_CFGR_SW;                               /* Select PLL as system clock source */
  RCC->CFGR |=  RCC_CFGR_SW_PLL;
  while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);  /* Wait till PLL is system clock src */
}
