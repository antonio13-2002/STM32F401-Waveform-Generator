/* I'm using tim2 with channel 1 for generating PWM signal*/



#include <stdint.h>
#include "tim.h"
#include "gpio.h"
#include "pwm.h"
#include "stm32f4xx.h"

void tim2_pa5_PWM_mode(void){
	/*setting pin*/
	pa5_setting();
	/*enabling timer clock*/
	SET_BIT(RCC->APB1ENR,RCC_APB1ENR_TIM2EN);
	/*enabling prescaler, for having timer counter clock of 1MHz (t=0.1ms)*/
	TIM2->PSC = 1600U - 1;
	/*settings for PWM generation*/
	pwm_mode_1();
	/*Enabling the preload register*/
	SET_BIT(TIM2->CCMR1,TIM_CCMR1_OC1PE);
	/*inizializing registers setting UG bit*/
	SET_BIT(TIM2->EGR,TIM_EGR_UG); //because we are in upcounting mode, this bit clear value of the counter
	/*setting polarity of the output signal*/
	CLEAR_BIT(TIM2->CCER,TIM_CCER_CC1P);
	/*enabling output in OC1*/
	SET_BIT(TIM2->CCER,TIM_CCER_CC1E);
	/*Timer enable*/
	SET_BIT(TIM2->CR1,TIM_CR1_CEN);
}


