#include <stdint.h>
#include "pwm.h"
#include "stm32f4xx.h"

void pwm_mode_1(void){
	/*Setting the autoreload register, which determines value of frequency of PWM*/
	TIM2->ARR = 10000U;
	/*Setting the value of the duty cycle (50% for example)*/
	TIM2->CCR1 = 3000U;
	/*enabling PWM Mode 1*/
	MODIFY_REG(TIM2->CCMR1,TIM_CCMR1_OC1M,6U<<(TIM_CCMR1_OC1M_Pos)); //when counter < ccr1, output is high
}
