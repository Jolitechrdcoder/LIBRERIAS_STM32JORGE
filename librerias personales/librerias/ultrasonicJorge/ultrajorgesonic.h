/* Creada por:
 *
 *  Jorge Luis Martínez Suárez
 *  06/03/2023
 * */
#ifndef INC_ULTRAJORGESONIC_H_
#define INC_ULTRAJORGESONIC_H_

#include "stm32f3xx_hal.h" // si tienes otra familia de microcontroladores, reemplaza "f3" por "f4", por ejemplo.
// aquí cambian por los pines que utilices
//*************************************************
#define TRIG_PIN GPIO_PIN_9 // PA9 = D8
#define TRIG_PORT GPIOA
#define ECHO_PIN GPIO_PIN_8 // PA8 = D7
#define ECHO_PORT GPIOA
//*************************************************
// función que inicializa el timer.
void ultrasonido_init(void);
// lógica de medición de distancias.
uint16_t ultrasonido_medir_distancia(void);

#endif /* INC_ULTRAJORGESONIC_H_ */
