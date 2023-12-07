/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void delayMicroseconds(uint32_t us);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED0_Pin GPIO_PIN_13
#define LED0_GPIO_Port GPIOC
#define LEDH_Pin GPIO_PIN_0
#define LEDH_GPIO_Port GPIOA
#define LEDG_Pin GPIO_PIN_1
#define LEDG_GPIO_Port GPIOA
#define LEDF_Pin GPIO_PIN_2
#define LEDF_GPIO_Port GPIOA
#define LEDE_Pin GPIO_PIN_3
#define LEDE_GPIO_Port GPIOA
#define OLED_CS_Pin GPIO_PIN_4
#define OLED_CS_GPIO_Port GPIOA
#define OLED_RES_Pin GPIO_PIN_0
#define OLED_RES_GPIO_Port GPIOB
#define OLED_DC_Pin GPIO_PIN_1
#define OLED_DC_GPIO_Port GPIOB
#define LEDA_Pin GPIO_PIN_12
#define LEDA_GPIO_Port GPIOB
#define LEDB_Pin GPIO_PIN_13
#define LEDB_GPIO_Port GPIOB
#define LEDC_Pin GPIO_PIN_14
#define LEDC_GPIO_Port GPIOB
#define LEDD_Pin GPIO_PIN_15
#define LEDD_GPIO_Port GPIOB
#define SEG0_Pin GPIO_PIN_9
#define SEG0_GPIO_Port GPIOA
#define SEG1_Pin GPIO_PIN_10
#define SEG1_GPIO_Port GPIOA
#define SEG2_Pin GPIO_PIN_11
#define SEG2_GPIO_Port GPIOA
#define SEG3_Pin GPIO_PIN_12
#define SEG3_GPIO_Port GPIOA
#define SEG4_Pin GPIO_PIN_15
#define SEG4_GPIO_Port GPIOA
#define SEG5_Pin GPIO_PIN_3
#define SEG5_GPIO_Port GPIOB
#define SEG6_Pin GPIO_PIN_4
#define SEG6_GPIO_Port GPIOB
#define SEG7_Pin GPIO_PIN_5
#define SEG7_GPIO_Port GPIOB
#define KNOB_Pin GPIO_PIN_9
#define KNOB_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
