#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "tim.h"
#include "dma.h"
#include "sin.h"
#include <math.h>

uint32_t vet[SIZE];


int main(void)
{
	SCB->CPACR |= ((3UL << 20)|(3UL << 11*2)); //enabling fpu
	printf("Starting dim\n");
	sin_generation(vet);
	/*timer settings for PWM generation*/
	tim2_pa5_PWM_mode();
	tim3_interrupt_generation();
	/*setting dma transfer*/
	dma_settings(vet); //include the samples vector

	while(1)
	{
		; //loop forever
	}
}
