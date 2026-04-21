/*I'm creating a signal generator emulator using the STM32.
 * These are the signal that can generate:
 * -Sine wave
 * -Triangular wave
 * -Sawtooth wave
 * -Stepped signal
 * -Continuous signal*/

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "tim.h"
#include "dma.h"
#include "choice.h"
#include "signals.h"

uint16_t choice;
uint32_t vet[SIZE];

int main(void)
{	uint32_t ns;
	SCB->CPACR |= ((3UL << 20)|(3UL << 11*2)); //enabling fpu
	UART2_Init();
    printf("Starting dim \n"); //debug message
    /*signal choise message*/
    printf("Select the waveform you want to generate: \n");
    printf("1: Sine wave\n");
    printf("2: Triangular wave\n");
    printf("3: Sawtooth wave\n");
    printf("4: Stepped signal\n");
    printf("5: Continuous signal\n");
    printf("6: Exit\n");
    scanf("%hu",&choice);
    if(choice == 6){
    	printf("Exiting...\n");
    	return -1;
    }
    else{
    	/*signal generation*/
    	ns = signal_sample_generation(choice);
    	tim2_pa5_PWM_mode(); //hardware settings
    	tim3_interrupt_generation();
    	/*dma transfer*/
    	dma_settings(vet,ns);
    	while(1){
    		; //do nothing
    	}
    }
}
