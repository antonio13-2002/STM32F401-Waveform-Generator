#include <stdint.h>
#include "stm32f4xx.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

void tim2_pa5_PWM_mode(void){
	pa5_setting();
	/*enabling timer clock*/
	SET_BIT(RCC->APB1ENR,RCC_APB1ENR_TIM2EN);
	/*setting prescaler*/
	TIM2->PSC = 16U - 1;
	/*setting PWM mode*/
	pwm_mode1();
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

void tim3_interrupt_generation(void){
	/*enabling timer clock*/
	SET_BIT(RCC->APB1ENR,RCC_APB1ENR_TIM3EN);
	TIM3->PSC = TIM2->PSC; // the f3_cnt has to be equal to f2_cnt
	/*we want an updating event every 1 PWM period*/
	TIM3->ARR = 99U;
	/*enabling update interrupt*/
	SET_BIT(TIM3->CR1,TIM_CR1_CEN);
}



