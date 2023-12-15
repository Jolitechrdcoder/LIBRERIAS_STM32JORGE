/*
 * nema17_jorge.c
 *
 * Created on: Sep 17, 2023
 * Author: Jorge Luis Martinez Suarez
 */
#include "nema17_jorge.h"
#include "stm32f3xx_hal.h"

extern TIM_HandleTypeDef htim1; // Declarar la variable htim1 que se utiliza en microDelay

void microDelay(uint16_t delay)
{
  __HAL_TIM_SET_COUNTER(&htim1, 0);
  while (__HAL_TIM_GET_COUNTER(&htim1) < delay);
}

void step(const NEMA17_Config *config, int steps, uint8_t direction, uint16_t delay)
{
  int x;
  if (direction == 0)
    HAL_GPIO_WritePin(config->dirPort, config->dirPin, GPIO_PIN_SET);
  else
    HAL_GPIO_WritePin(config->dirPort, config->dirPin, GPIO_PIN_RESET);

  for (x = 0; x < steps; x = x + 1)
  {
    HAL_GPIO_WritePin(config->stepPort, config->stepPin, GPIO_PIN_SET);
    microDelay(delay);
    HAL_GPIO_WritePin(config->stepPort, config->stepPin, GPIO_PIN_RESET);
    microDelay(delay);
  }
}
