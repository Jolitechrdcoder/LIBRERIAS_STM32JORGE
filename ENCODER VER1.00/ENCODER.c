/*
 * ENCODER.h
 *
 *  Created on: Apr 4, 2024
 *      Author: jorge luis Martinez
 *      Alias:MecatronicosRD
 */

#include "ENCODER.h"

#define maxport GPIOB
#define a1 GPIO_PIN_4
#define b1 GPIO_PIN_5
int counter=0;
void encoder_loop(void){

	if (HAL_GPIO_ReadPin(maxport, a1) == GPIO_PIN_RESET)
		  {
	          if (HAL_GPIO_ReadPin(maxport, b1) == GPIO_PIN_RESET)
	              {
	        	  while(HAL_GPIO_ReadPin(maxport, b1) == GPIO_PIN_RESET){};
				   counter--;
				  while(HAL_GPIO_ReadPin(maxport, a1) == GPIO_PIN_RESET){};
				  HAL_Delay(10);
			      }




	          if (HAL_GPIO_ReadPin(maxport, b1) == GPIO_PIN_SET)
	                        {
	                  	  while(HAL_GPIO_ReadPin(maxport, b1) == GPIO_PIN_SET){};
	          			   counter++;
	          			  while(HAL_GPIO_ReadPin(maxport, a1) == GPIO_PIN_RESET){};
	          			 while(HAL_GPIO_ReadPin(maxport, b1) == GPIO_PIN_RESET){};

	          			  HAL_Delay(10);
	          		      }

	                  if (counter >= 31) {
	                      counter = 0;
	                  }

		  }
}
