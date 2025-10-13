#include "main.h"
#include "stm32f1xx_hal.h"

/* ---- handles ---- */

/* brightness table (percent) */
const uint8_t duty_table[5] = {0, 25, 50, 75, 100};
volatile uint8_t duty_index = 0;
volatile uint32_t last_button_ms = 0; // debounce

/* Systemclock configure */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /* HSE and PLL to reach 72 MHz */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON; // change if using HSI
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /* Configure clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // 72MHz
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // HCLK = 72MHz
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;         // PCLK1 = 36MHz
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         // PCLK2 = 72MHz

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}
/* ---------------- Peripherals init ---------------- */
//enable clock
void RCC_Config(void) {
    // Enable GPIOA and TIM2 clock
    // --- 1) Enable clocks ---
    RCC->APB2ENR |= (1 << 0);   // AFIO (for interrupt)
    RCC->APB2ENR |= (1 << 2);   // GPIOA
    RCC->APB2ENR |= (1 << 3);   // GPIOB
    RCC->APB1ENR |= (1 << 0);   // TIM2
}
//gpio setup
void GPIO_Config(void) {
    // PA0 (TIM2_CH1) as output
	GPIOA->CRL &= ~(0xF << 0);
	GPIOA->CRL |=  (0xB << 0);   // 0b1011 -> Output

	// PB9 as input(button)
	GPIOB->CRH &= ~(0xF << 4);
	GPIOB->CRH |= (0x8 << 4);   // 0b1000 -> input
	GPIOB->ODR |= (0X1 << 9);	// pull-up

	 // Map EXTI9 -> PB9
	AFIO->EXTICR[2] &= ~(0xF << 4); // clear bits [7:4] for EXTI9
	AFIO->EXTICR[2] |=  (0x1 << 4); // map EXTI9 to port B

	// Clear pending EXTI line9
	EXTI->PR = (1UL << 9);                // clear PR9

	// Enable EXTI line9 interrupt (falling edge only)
	EXTI->IMR |= (1UL << 9);  // IMR
	EXTI->RTSR &= ~(1UL << 9);            // disable rising trigger for line 9
	EXTI->FTSR |=  (1UL << 9);            // enable falling trigger for line 9

	// NVIC enable
	NVIC->ISER[0] = (1 << 23);  // Enable EXTI9_5 interrupt
}

void TIM2_Config(void) {
    // Prescaler and auto-reload
	TIM2->PSC  = 72 - 1;		// prescaler
	TIM2->ARR  = 999 - 1;		// 999 period

	/* 1) initial duty = 0% */
	TIM2->CCR1 = 0;  // TIM2_CCR1 = 0

	/* 2) configure CCMR1: clear lower byte then set OC1PE=1, OC1M=110 (PWM1) */
	TIM2->CCMR1 &= ~0xFFU;                        // clear OC1/CC1 fields
	TIM2->CCMR1 |= (6U << 4) | (1U << 3);         // OC1M = 110 (PWM1), OC1PE = 1

	/* 3) enable CC1 output */
	TIM2->CCER |= (1U << 0);                      // CC1E = 1

	/* 4) generate update event to load PSC/ARR/CCR shadow into active registers */
	TIM2->EGR |= (1U << 0);                       // UG = 1

	/* 5) enable ARPE and start timer */
	TIM2->CR1 |= (1U << 7) | (1U << 0);           // ARPE = 1, CEN = 1

	/* Timer is already running (MMIO). Set initial duty = 0% */
	TIM2->CCR1 = 0;

}
/* IRQ handlers */
void EXTI9_5_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_9);
}

/* EXTI callback for PB9 (EXTI9_5) */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_9) {
    uint32_t now = HAL_GetTick();
    if ((now - last_button_ms) > 100) { // 50 ms debounce
      last_button_ms = now;
      duty_index++;
      if (duty_index >= (sizeof(duty_table)/sizeof(duty_table[0]))) duty_index = 0;

      uint32_t pulse = (uint32_t)duty_table[duty_index] * 1000 / 100;  // ARR=999+1=1000
      TIM2->CCR1 = pulse;  // TIM2_CCR1 = pulse
    }
  }
}

int main(void)
{
  //initialize
  HAL_Init();
  SystemClock_Config();
  RCC_Config();
  GPIO_Config();
  TIM2_Config();

  while (1)
  {
    __WFI(); // wait for interrupt - low power
  }
}

/* Error handler */
void Error_Handler(void)
{
  __disable_irq();
  while (1) { }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  /* report file/line if desired */
}
#endif
