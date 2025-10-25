/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body (WWDG demo)
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"

/* Private variables ---------------------------------------------------------*/
WWDG_HandleTypeDef hwwdg;

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_WWDG_Init(void);

/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize GPIO (PC13 LED) */
  MX_GPIO_Init();

  /* --- Detect previous reset flags and blink BEFORE enabling WWDG --- */
  if (RCC->CSR & RCC_CSR_WWDGRSTF) {
    /* Clear reset flags */
    RCC->CSR |= RCC_CSR_RMVF;
    /* Blink LED 3x to indicate WWDG reset */
    for (int i = 0; i < 3; ++i) {
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); /* LED ON (active-low) */
      HAL_Delay(150);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);   /* LED OFF */
      HAL_Delay(150);
    }
  } else if (RCC->CSR & RCC_CSR_IWDGRSTF) {
    /* Clear reset flags */
    RCC->CSR |= RCC_CSR_RMVF;
    /* Blink LED 3x to indicate IWDG reset */
    for (int i = 0; i < 3; ++i) {
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); /* LED ON */
      HAL_Delay(150);
      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);   /* LED OFF */
      HAL_Delay(150);
    }
  }

  /* Initialize and start the WWDG AFTER the blink */
  MX_WWDG_Init();

  /* USER CODE BEGIN 2 */
  uint32_t start = HAL_GetTick();
  int stop_feeding = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  while (1)
  {
    /* If not yet requested to stop feeding, refresh WWDG periodically */
    if (!stop_feeding) {
      /* Refresh WWDG (write counter). Use HAL wrapper here. */
      if (HAL_WWDG_Refresh(&hwwdg) != HAL_OK) {
        /* Refresh failed — go error */
        Error_Handler();
      }

      /* Heartbeat: short blink while feeding */
//      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); /* LED ON */
//      HAL_Delay(10);
//      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);   /* LED OFF */

      /* Sleep ~20 ms -> total roughly 30 ms between refreshes (safe for ~50 ms timeout) */
      HAL_Delay(20);
    } else {
      /* Stop feeding: simulate a hang so WWDG will reset device */
      while (1) { __NOP(); }
    }

    /* After 2000 ms stop feeding to demonstrate reset */
    if ((HAL_GetTick() - start) > 2000U) {
      stop_feeding = 1;
    }
  }
}

/**
  * @brief System Clock Configuration
  *        (keeps your existing HSI config as in the template)
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL5;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief WWDG Initialization Function
  * @param None
  * @retval None
  *
  * Note: Window and Counter set to 64 in your template — on PCLK1 = HSI (8 MHz here)
  * the timeout will be short. For Blue Pill typical PCLK1=36MHz -> timeout ~58ms max.
  */
static void MX_WWDG_Init(void)
{
  hwwdg.Instance = WWDG;
  hwwdg.Init.Prescaler = WWDG_PRESCALER_8; /* largest prescaler for longest timeout */
  hwwdg.Init.Window = 0x7F;   /* 0..0x7F (7-bit) */
  hwwdg.Init.Counter = 78;  /* 0x40..0x7F (start value) */
  hwwdg.Init.EWIMode = WWDG_EWI_DISABLE;  // optional: disable EWI if you don't use callback

  if (HAL_WWDG_Init(&hwwdg) != HAL_OK)
  {
    Error_Handler();
  }

  /* Enable WWDG IRQ in NVIC (EWI triggers WWDG_IRQn) */
  HAL_NVIC_SetPriority(WWDG_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(WWDG_IRQn);
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  *
  * Initializes PC13 (on-board LED) as push-pull output
  */
static void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOC_CLK_ENABLE();

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Configure PC13 as output push-pull (2 MHz) */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* LED off (PC13 is usually active-low on Blue Pill) */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
}

/* USER CODE BEGIN 4 */

/**
 * @brief  WWDG IRQ handler
 *         Calls HAL handler which will call the early-wakeup callback.
 */
void WWDG_IRQHandler(void)
{
  HAL_WWDG_IRQHandler(&hwwdg);
}

/**
 * @brief  Early Wakeup callback called by HAL when EWI occurs (WWDG counter reached the EWI threshold).
 *         Use this to perform last-second tasks; keep it short.
 */
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg_ptr)
{
  /* Toggle LED briefly to indicate EWI fired */
  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
    /* blink fast to indicate error */
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
    HAL_Delay(80);
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_Delay(80);
  }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add reporting here */
}
#endif /* USE_FULL_ASSERT */
