/* I will use TIM5, which is a general purpose timer, for capturing input signal when is on rising edge.
 * So i will enable the RCC register of APB1 bus, on which TIM5 is interfaced. I will use CH3 for reading
 * the signal, and PA2 set in input mode
*/


#include "stm32f4xx.h"
#include <stdint.h>
#include <stdio.h>
#include "tim.h"

uint32_t value1 = 0;
uint32_t value2 = 0;
float frequency = 0;
uint32_t diff = 0;

int main(void)
{
	SCB->CPACR |= ((3UL << 20)|(3UL << 11*2)); //enabling fpu
	tim2_pa5_input_capture(); //setup

    while(1){
    	while(!(READ_BIT(TIM2->SR,TIM_SR_CC1IF))){


    	}
    	if (value1 == 0){
    		value1 = TIM2->CCR1;
    	}else{
    		value2 = TIM2->CCR1;
    		if(value1 <= value2){
    			diff = (value2-value1);
    		}else{
    			diff = ((READ_REG(TIM2->ARR))-value1)+value2+1;
    		}
    		if (diff != 0){
    			frequency = (float)1000000/diff;
    		}else {
    			frequency = 0;
    		}
    		printf("frequency = %f\n",frequency);
    		value1 = 0;
    		value2 = 0;
    	}
    	CLEAR_BIT(TIM2->SR,TIM_SR_CC1IF);

    }
}
