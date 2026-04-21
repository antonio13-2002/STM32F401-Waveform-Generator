/*Implementing the timer clock configuration for reading the PWM signal, and
 * measuring its period and duty cycle. I use TIM5 and CH3 and CH4 for this purpose
 */

#include <stdint.h>
#include "stm32f4xx.h"
#include "tim.h"
#include "active_input.h"

void tim2_pa5_pa1_PWM_input_mode(void){
	/*Enabling the clock for GPIOA (for PA5 & PA1)*/
	SET_BIT(RCC->AHB1ENR,RCC_AHB1ENR_GPIOAEN);
	/*setting PA5 in alternate function mode*/
	MODIFY_REG(GPIOA->MODER,GPIO_MODER_MODER5,2U<<(GPIO_MODER_MODER5_Pos));
	/*enabling the alternate function for PA5*/
	MODIFY_REG(GPIOA->AFR[0],GPIO_AFRL_AFSEL5,1U<<(GPIO_AFRL_AFSEL5_Pos));
	//enabling PA1
	tim2_pa1_PWM_duty_cycle_reading();
	/*enabling clock for TIM2*/
	SET_BIT(RCC->APB1ENR,RCC_APB1ENR_TIM2EN);
	/*selecting active input for measuring the period*/
	active_input_N_channel(1);
	active_input_N_channel(2);
	/*selecting input valid trigger*/
	MODIFY_REG(TIM2->SMCR,TIM_SMCR_TS,5U<<(TIM_SMCR_TS_Pos));
	/*configuring slave mode controller in reset mode*/
	MODIFY_REG(TIM2->SMCR,TIM_SMCR_SMS,4U<<(TIM_SMCR_SMS_Pos));
	/*Enabling captures*/
	SET_BIT(TIM2->CCER,TIM_CCER_CC1E);
	SET_BIT(TIM2->CCER,TIM_CCER_CC2E);
	/*Timer enable*/
	SET_BIT(TIM2->CR1,TIM_CR1_CEN);
	SET_BIT(TIM2->DIER,TIM_DIER_CC1IE);
	SET_BIT(TIM2->DIER,TIM_DIER_CC2IE);


}

void tim2_pa1_PWM_duty_cycle_reading(void){
	/*setting PA1 in alternate function mode*/
	MODIFY_REG(GPIOA->MODER,GPIO_MODER_MODER1,2U<<(GPIO_MODER_MODER1_Pos));
	/*enabling the alternate function for PA1*/
	MODIFY_REG(GPIOA->AFR[0],GPIO_AFRL_AFSEL1,1U<<(GPIO_AFRL_AFSEL1_Pos));
}


