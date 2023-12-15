/*
 * PWM.C
 *
 *  Created on: Apr 8, 2023
 *      Author: Alcides Ramos
 */

#include "PWM.h"


void  PWM_init(TIM_HandleTypeDef *PWM,uint16_t canal)
{

HAL_TIM_PWM_Start(PWM, canal);

}

void pwm_valor(uint32_t *canal,float valor)
{
	//PWMTIM1->ARR   =100
	 //    ?         =valor

*canal=valor*(float)PWMTIM1->ARR/100.0;  // lo escala de 0 a 100%

}
