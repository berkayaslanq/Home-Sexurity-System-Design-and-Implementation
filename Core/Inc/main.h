/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "stm32g0xx_hal.h"


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

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */
#define REED_SWITCH_Pin GPIO_PIN_7
#define REED_SWITCH_GPIO_Port GPIOB

#define PANIC_BUTTON_Pin GPIO_PIN_0
#define PANIC_BUTTON_GPIO_Port GPIOB

#define MOTION_SENSOR_Pin GPIO_PIN_4
#define MOTION_SENSOR_GPIO_Port GPIOA

#define RAIN_SENSOR_D_Pin GPIO_PIN_7
#define RAIN_SENSOR_D_GPIO_Port GPIOA

#define DHT21_Pin GPIO_PIN_5
#define DHT21_Port GPIOA

#define MQ7_Pin GPIO_PIN_6
#define MQ7_Port GPIOA



typedef enum {
    SENSOR_STATE_OFF = 0,
    SENSOR_STATE_ON  = 1
} eSensorState_t;

typedef enum {
    SENSOR_TYPE_DIGITAL,
    SENSOR_TYPE_ANALOG,
    SENSOR_TYPE_SPECIAL
} eSensorType_t;

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
