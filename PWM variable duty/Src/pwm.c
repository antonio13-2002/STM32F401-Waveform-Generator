#include <stdint.h>
#include "pwm.h"
#include "stm32f4xx.h"

void pwm_mode1(){
	/*Setting the autoreload register, which determines value of frequency of PWM*/
	TIM2->ARR = 100U; //pwm period = 1cs
	/*variable duty cycle: the value of the CCR1 register has to change with a 1sec period*/
	/*enabling PWM Mode 1*/
	MODIFY_REG(TIM2->CCMR1,TIM_CCMR1_OC1M,6U<<(TIM_CCMR1_OC1M_Pos)); //when counter < ccr1, output is high

}

