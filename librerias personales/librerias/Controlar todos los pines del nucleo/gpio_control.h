#ifndef GPIO_CONTROL_H
#define GPIO_CONTROL_H

#include "stm32f3xx_hal.h"
//created by jorge
void gpio_pin_on(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void gpio_pin_off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void gpio_pins_on(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pins);
void gpio_pins_off(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pins);

#endif /* GPIO_CONTROL_H */
