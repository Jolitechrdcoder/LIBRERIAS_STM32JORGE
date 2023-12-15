// stepper.c
//modify by jorge luis martinez suarez.
//06/05/2023


#include "main.h"
#include "stm32f3xx_hal.h"
#include "StepMotor.h"

float anglePerSequence = 0.703125;
//funcion activacion de las bobinas stepper
void stepper_half_drive(int Paso) {
    const int pinValues[][4] = {
        {1, 0, 0, 0}, // Paso 0
        {1, 1, 0, 0}, // Paso 1
        {0, 1, 0, 0}, // Paso 2
        {0, 1, 1, 0}, // Paso 3
        {0, 0, 1, 0}, // Paso 4
        {0, 0, 1, 1}, // Paso 5
        {0, 0, 0, 1}, // Paso 6
        {1, 0, 0, 1}  // Paso 7
    };

    if (Paso >= 0 && Paso < 8) {
        HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, pinValues[Paso][0]);
        HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, pinValues[Paso][1]);
        HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, pinValues[Paso][2]);
        HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, pinValues[Paso][3]);
    }
}

//funcion velocidad
void stepper_set_rpm (int rpm)  //rpm maximo 13 y minimo 5
{
	delay(60000000/stepsperrev/rpm);
}



// funcion cambio de direccion
void stepper_step_angle(float angle, int direction, int rpm) {
    int numberOfSequences = (int)(angle / anglePerSequence);

    for (int seq = 0; seq < numberOfSequences; seq++) {
        int startStep = (direction == 0) ? 7 : 0;
        int endStep = (direction == 0) ? -1 : 8;
        int stepIncrement = (direction == 0) ? -1 : 1;

        for (int step = startStep; step != endStep; step += stepIncrement) {
            stepper_half_drive(step);
            stepper_set_rpm(rpm);
        }
    }
}
