/*
 * PWM.H
 *
 *  Created on: Apr 8, 2023
 *      Author: Alcides Ramos
 */

#include "main.h"

#ifndef LIBRERIAS_PWM_H_
#define LIBRERIAS_PWM_H_

//info relacionada a los servos

/*
#define PWMT1 htim1
#define PWMTIM1 TIM1

#define PWM1_CH TIM_CHANNEL_1
#define PWM1 TIM1->CCR1


#define PWM2_CH TIM_CHANNEL_2
#define PWM2 TIM1->CCR2
*/

//LIMITES PARA MOTORES DC




void PWM_init(TIM_HandleTypeDef *serv,uint16_t canal);
void pwm_valor(uint32_t *canal,float valor);



#endif /* LIBRERIAS_PWM_H_ */
