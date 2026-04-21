#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "tim.h"

uint32_t cnt1 = 0;
uint32_t cnt2 = 0;
float frequency = 0;
float duty = 0;

int main(void)
{
	SCB->CPACR |= ((3UL << 20)|(3UL << 11*2)); //enabling fpu
	tim2_pa5_pa1_PWM_input_mode(); //setting timer and pins

    while(1){
    	while(!(READ_BIT(TIM2->SR,TIM_SR_CC1IF) || READ_BIT(TIM2->SR,TIM_SR_CC2IF))){
    		//do nothing
    	}
    	if(cnt2 == 0){
    		cnt2 = READ_REG(TIM2->CCR2); //value in edge
    	}
    	else {
    		cnt1 = READ_REG(TIM2->CCR1); //value in next rising edge
    		/*calculate frequency*/
    		frequency = (float)16000000/cnt1;
    		duty = (float)cnt2/cnt1*100;

    		printf("Frequency = %.2f \n",frequency);
    		printf("Duty cycle = %.2f \n",duty);
    		cnt1 = 0;
    		cnt2 = 0;
    	}
    	CLEAR_BIT(TIM2->SR,TIM_SR_CC1IF);
    	CLEAR_BIT(TIM2->SR,TIM_SR_CC2IF);
    }
}
