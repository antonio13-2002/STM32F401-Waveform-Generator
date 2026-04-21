#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx_hal_.h"

extern UART_HandleTypeDef *console_io_uart_ptr;
UART_HandleTypeDef huart2;
char str[60];

uint16_t choice;
uint32_t vet[SIZE];

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
    scanf("%hu",&choice);


    while(1){
    	;
    }
}
