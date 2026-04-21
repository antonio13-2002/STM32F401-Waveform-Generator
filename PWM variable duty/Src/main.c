#include <stdint.h>
#include "stm32f4xx.h"
#include "tim.h"
#include "dma.h"
#include "main.h"

uint32_t duty_cycles[BUFFER_DIM]={90U,80U,70U,60U,50U,40U,30U,20U,10U,0U}; //various duty cycles
int main(void)
{
	tim2_pa5_PWM_mode();//setting timer and output port
	tim3_interrupt_generation();//enabling interrupt generation
	dma_setting(duty_cycles); //setting the DMA communication
	while(1){
		;//DMA automatically changes the value of the duty cycle, we do not have to do nothing
	}
}
