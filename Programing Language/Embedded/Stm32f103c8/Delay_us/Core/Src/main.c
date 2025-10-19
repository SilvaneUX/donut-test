/* main.c - robust blink using DWT_us with fallback */
#include "main.h"
#include "stm32f1xx_hal.h"



static uint32_t cycles_per_us;

static inline void DWT_Init_and_calc(void)
{
    CoreDebug->DEMCR |= (1 << 24);		//CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    cycles_per_us = (uint32_t)(SystemCoreClock / 1000000UL);
}

/* fast inline microsecond delay */
static inline void DWT_Delay_us_fast(uint32_t us)
{
    uint32_t cycles = us * cycles_per_us;
    if (cycles == 0) return;
    uint32_t start = DWT->CYCCNT;
    while ((uint32_t)(DWT->CYCCNT - (start-72)) < (cycles)) { __NOP(); }
}

#define DELAY_MS(ms) \
    do { \
    	for (uint32_t i = 0; i < ms; ++i) { \
    		DWT_Delay_us_fast(1000); \
    	        } \
    } while (0)

/* Try HSE+PLL; on failure fall back to HSI */
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
        SystemClock_Config_Fallback_HSI();
        return;
    }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                 |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // 72MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
        SystemClock_Config_Fallback_HSI();
        return;
    }
}

void SystemClock_Config_Fallback_HSI(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) { Error_Handler(); }

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                 |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI; // 8 MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK) { Error_Handler(); }
}

void Periph_Config(void)
{
    /* enable GPIOC clock for user LED (common on BluePill) */
    RCC->APB2ENR |= (1 << 2);   // IOPCEN
    (void)RCC->APB2ENR;         // readback

    /* Configure PC13 as general purpose output (push-pull) low speed:
       field = CRH bit index for pin13 = (13-8)=5 -> bits [23:20]
       MODE = 01 (2 MHz) CNF = 00 (GP push-pull) => value 0x1
       full nibble = 0x1 << (5*4) */
    GPIOA->CRL &= ~(0xF << 0);
    GPIOA->CRL |=  (0x3 << 0); // MODE13=01, CNF13=00
    GPIOA->ODR &= ~(1 << 13);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    SystemCoreClockUpdate();
    Periph_Config();
    DWT_Init_and_calc();

//    int dwt_ok = (DWT_Delay_Init() == 0) ? 1 : 0;

    while (1) {
        GPIOA->ODR |= (1 << 0);         // toggle PC13 LED
        DWT_Delay_us_fast(10);   // request 1 us
//        DWT_Delay_us(1);        // 500 ms
        GPIOA->ODR &= ~(1 << 0);         // toggle PC13 LED
        DWT_Delay_us_fast(10);   // request 1 us
//        DWT_Delay_us(1);        // 500 ms
    }
}

/* Error handler */
void Error_Handler(void) {
    __disable_irq();
    while (1) { }
}
