#include "Servo.h"
//created by jorge luis and chat gpt ;)
#define SERVO_ANGLE_MIN 0
#define SERVO_ANGLE_MAX 180

static uint16_t Servo_GetCurrentAngle(Servo *servo) {
    uint32_t pulseWidth = __HAL_TIM_GET_COMPARE(servo->htim, servo->channel);
    uint16_t angle = (pulseWidth - 500) / 10;
    return angle;
}

void Servo_Init(Servo *servo, TIM_HandleTypeDef *htim, uint32_t channel) {
    servo->htim = htim;
    servo->channel = channel;
    HAL_TIM_PWM_Start(servo->htim, servo->channel);
}

void Servo_SetAngle(Servo *servo, uint16_t angle) {
    if (angle < SERVO_ANGLE_MIN) {
        angle = SERVO_ANGLE_MIN;
    } else if (angle > SERVO_ANGLE_MAX) {
        angle = SERVO_ANGLE_MAX;
    }

    uint32_t pulseWidth = (uint32_t)(500 + angle * 10);
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, pulseWidth);
}

void Servo_MoveToAngle(Servo *servo, uint16_t targetAngle, uint16_t timeMs) {
    uint16_t currentAngle = Servo_GetCurrentAngle(servo);
    int16_t angleDiff = targetAngle - currentAngle;
    uint16_t step = angleDiff > 0 ? 1 : -1;
    uint16_t delay = timeMs / abs(angleDiff);

    for (uint16_t angle = currentAngle; angle != targetAngle; angle += step) {
        Servo_SetAngle(servo, angle);
        HAL_Delay(delay);
    }

    Servo_SetAngle(servo, targetAngle);
}
