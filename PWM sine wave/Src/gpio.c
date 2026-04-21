#include <stdint.h>
#include "gpio.h"
#include "stm32f4xx.h"

void pa5_setting(void){
	/*enabling PA5 clock*/
	SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
	/*setting PA5 in alternate function mode*/
	MODIFY_REG(GPIOA->MODER,GPIO_MODER_MODER5,2U<<(GPIO_MODER_MODER5_Pos));
	/*setting the alternate function*/
	MODIFY_REG(GPIOA->AFR[0],GPIO_AFRL_AFSEL5,1U<<(GPIO_AFRL_AFSEL5_Pos));
}

