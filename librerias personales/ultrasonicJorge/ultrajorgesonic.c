

/* Creada por:
 *
 *  Jorge Luis Martínez Suárez
 *  06/03/2023
 * */

#include "ultrajorgesonic.h"

#define timmer htim1 // reemplazar por el timer que utilicen

extern TIM_HandleTypeDef timmer;

void ultrasonido_init(void) {
    HAL_TIM_Base_Start(&timmer);
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET); // pongo el trigger en bajo
}

uint16_t ultrasonido_medir_distancia(void) {
    uint32_t pMillis = HAL_GetTick();
    uint32_t Valor1 = 0;
    uint32_t Valor2 = 0;

    uint16_t Distancia = 0;  // cm

    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);  // pongo el trigger en alto
    __HAL_TIM_SET_COUNTER(&timmer, 0);
    while (__HAL_TIM_GET_COUNTER(&timmer) < 10);  // espero 10 us
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pongo el trigger en bajo nuevamente.

    pMillis = HAL_GetTick();
    // espero a que el eco reciba el 1 del trigger
    while (!(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)) && pMillis + 10 > HAL_GetTick());
    Valor1 = __HAL_TIM_GET_COUNTER(&timmer);

    pMillis = HAL_GetTick();
    // espero a que el pin echo esté en bajo
    while ((HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)) && pMillis + 50 > HAL_GetTick());
    Valor2 = __HAL_TIM_GET_COUNTER(&timmer);
    Distancia = (Valor2 - Valor1) * 0.034 / 2;

    // retornar el valor de la distancia
    return Distancia;
}
