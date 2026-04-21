#include <stdint.h>
#include "pwm.h"
#include "stm32f4xx.h"

void pwm_mode1(void){
	/*setting the autoreload register, which determines the value of the frequency*/
	TIM2->ARR = 99U;
	//we have to transfer periodically a value to the CCR1 register, changing the duty cycle
	/*enabling PMW mode 1*/
	MODIFY_REG(TIM2->CCMR1,TIM_CCMR1_OC1M,6U<<(TIM_CCMR1_OC1M_Pos));
}

