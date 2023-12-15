



#include "ULTRASONICO.h"

#define timmer htim1 // reemplazan por el timmer que utilizen

extern TIM_HandleTypeDef timmer;

void ultrasonic_init(void) {
    HAL_TIM_Base_Start(&timmer);
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET); // ponggo el trigger en bajo
}


uint16_t ultrasonic_measure_distance(void) {
    uint32_t pMillis = HAL_GetTick();
    uint32_t Value1 = 0;
    uint32_t Value2 = 0;

    uint16_t Distance  = 0;  // cm*/
    HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_SET);  // pongo el trigger el alto
          __HAL_TIM_SET_COUNTER(&timmer, 0);
          while (__HAL_TIM_GET_COUNTER (&timmer) < 10);  // espero 10 us
          HAL_GPIO_WritePin(TRIG_PORT, TRIG_PIN, GPIO_PIN_RESET);  // pongo el trigger en bajo nuevamente.

          pMillis = HAL_GetTick();
          // espero que el ecco reciba el 1 del trigger
          while (!(HAL_GPIO_ReadPin (ECHO_PORT, ECHO_PIN)) && pMillis + 10 >  HAL_GetTick());
          Value1 = __HAL_TIM_GET_COUNTER (&timmer);

          pMillis = HAL_GetTick();
          // espero que el pin ecco este en bajo
          while ((HAL_GPIO_ReadPin (ECHO_PORT, ECHO_PIN)) && pMillis + 50 > HAL_GetTick());
          Value2 = __HAL_TIM_GET_COUNTER (&timmer);
          Distance = (Value2-Value1)* 0.034/2;

}
