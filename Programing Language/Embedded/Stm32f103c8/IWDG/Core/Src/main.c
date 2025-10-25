#include "main.h"
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        /* fallback to HSI if HSE/PLL fails */
//        SystemClock_Config_Fallback_HSI();
        return;
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                 |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // 72MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
//        SystemClock_Config_Fallback_HSI();
        return;
    }
}
void lsi_config(void)
{
	 /* Enable LSI for the independent watchdog */
	  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
	  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
//	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
//	    /* LSI start failed — continue but IWDG may not start */
//	  }
	  HAL_Delay(5); // allow LSI to stabilize
}
void GPIO_Config(void) {
	RCC->APB2ENR |= (1 << 4);  // GPIOC

    GPIOC->CRH &= ~(0xF << 20);      /* clear MODE13[1:0], CNF13[1:0] */
    GPIOC->CRH |=  (0x2 << 20);      /* MODE13 = 10 (Output 2 MHz), CNF13 = 00 (GP push-pull) */

    /* LED off initially (PC13 often active-low on Blue Pill) */
    GPIOC->BSRR = (1U << 13);        /* set PC13 -> LED off if active-low */
}
void iwdg_config(void)
{
    const uint16_t prescaler_div = 4;   /* allowed: 4,8,16,32,64,128,256 */
    const uint16_t reload = 999;       /* 0..4095 */

    /* Convert div to PR value (PR = 0..6 for div 4..256) */
    uint8_t pr_val = 0;
    switch (prescaler_div) {
        case 4:   pr_val = 0; break;
        case 8:   pr_val = 1; break;
        case 16:  pr_val = 2; break;
        case 32:  pr_val = 3; break;
        case 64:  pr_val = 4; break;
        case 128: pr_val = 5; break;
        case 256: pr_val = 6; break;
        default:  pr_val = 0; break;
    }

    /* Enable write access to PR and RLR */
    IWDG->KR = 0x5555;

    /* Program prescaler and reload */
    IWDG->PR  = pr_val & 0x7;
    IWDG->RLR = (uint32_t)(reload & 0x0FFF);

    /* Wait until the registers are updated (PVU/RVU cleared) */
//    while (IWDG->SR != 0) { /* wait */ }

    /* Reload counter so the new timeout starts from full value */
    IWDG->KR = 0xAAAA;

    /* Start the watchdog */
    IWDG->KR = 0xCCCC;
}
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	GPIO_Config();
	lsi_config();
	//detect iwdg resetting
	 if (RCC->CSR & RCC_CSR_IWDGRSTF) {
	        /* Clear reset flags so next boot can detect fresh resets */
	        RCC->CSR |= RCC_CSR_RMVF;

	        /* Blink LED 3x to indicate watchdog reset (active-low LED on PC13) */
	        for (int i = 0; i < 3; ++i) {
	            /* LED ON (reset bit in BSRR upper half) */
	            GPIOC->BSRR = (1U << (13 + 16)); /* reset PC13 -> LED ON */
	            HAL_Delay(150);
	            /* LED OFF */
	            GPIOC->BSRR = (1U << 13);        /* set PC13 -> LED OFF */
	            HAL_Delay(150);
	        }
	    }
	iwdg_config();
	while(1){
		IWDG->KR = 0xAAAA;
		if (HAL_GetTick() > 2000) {
			while(1){}
		}

	}
}
