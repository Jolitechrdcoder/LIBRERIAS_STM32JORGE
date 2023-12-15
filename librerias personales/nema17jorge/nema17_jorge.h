/*
 * nema17_jorge.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Jorge Luis Martinez Suarez
 */

#ifndef NEMA17_JORGE_H
#define NEMA17_JORGE_H

#include "stm32f3xx_hal.h"

typedef struct {
    GPIO_TypeDef *dirPort;
    uint16_t dirPin;
    GPIO_TypeDef *stepPort;
    uint16_t stepPin;
} NEMA17_Config;

void microDelay(uint16_t delay);
void step(const NEMA17_Config *config, int steps, uint8_t direction, uint16_t delay);

#endif /* NEMA17_JORGE_H */
