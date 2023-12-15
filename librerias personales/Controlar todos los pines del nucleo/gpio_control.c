#include "gpio_control.h"
//created by jorge
void gpio_pin_on(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_SET);
}

void gpio_pin_off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
  HAL_GPIO_WritePin(GPIOx, GPIO_Pin, GPIO_PIN_RESET);
}

void gpio_pins_on(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pins) {
  HAL_GPIO_WritePin(GPIOx, GPIO_Pins, GPIO_PIN_SET);
}

void gpio_pins_off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pins) {
  HAL_GPIO_WritePin(GPIOx, GPIO_Pins, GPIO_PIN_RESET);
}
