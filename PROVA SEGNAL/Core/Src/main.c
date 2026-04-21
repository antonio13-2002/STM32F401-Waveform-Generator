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
#include "main.h"

UART_HandleTypeDef huart2;
uint8_t choice[60];
int main(void)
{
    printf("Starting dim \n"); //debug message
    /*signal choise message*/
    printf("Select the waveform you want to generate: \n");
    printf("1: Sine wave\n");
    printf("2: Triangular wave\n");
    printf("3: Sawtooth wave\n");
    printf("4: Stepped signal\n");
    printf("5: Continuous signal\n");
    printf("6: Exit\n");
    //HAL_UART_Receive (&huart2,choice,sizeof(choice),10000);
    //printf("%u",choice);
}






