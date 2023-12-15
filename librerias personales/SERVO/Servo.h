#ifndef SERVO_H_
#define SERVO_H_
//created by jorge luis and chat gpt ;)
#include "stm32f3xx_hal.h"

typedef struct {
    TIM_HandleTypeDef *htim;
    uint32_t channel;
} Servo;

void Servo_Init(Servo *servo, TIM_HandleTypeDef *htim, uint32_t channel);
void Servo_SetAngle(Servo *servo, uint16_t angle);
void Servo_MoveToAngle(Servo *servo, uint16_t targetAngle, uint16_t timeMs);

#endif /* SERVO_H_ */
