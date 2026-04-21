#include "stm32f4xx.h"

void UART2_Init(void) {
    // Abilita il clock per la UART2 e per il GPIOA
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configura PA2 e PA3 come Alternate Function per UART2
    GPIOA->MODER &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3);
    GPIOA->MODER |= (GPIO_MODER_MODER2_1 | GPIO_MODER_MODER3_1);
    GPIOA->AFR[0] |= (7 << GPIO_AFRL_AFSEL2_Pos) | (7 << GPIO_AFRL_AFSEL3_Pos);

    // Configura UART2: Baud rate, 8 data bits, no parity, 1 stop bit
    USART2->BRR = 0x0683; // Configurazione per 9600 baud con clock a 16 MHz
    USART2->CR1 |= USART_CR1_RE | USART_CR1_TE; // Abilita trasmettitore e ricevitore
    USART2->CR1 |= USART_CR1_UE; // Abilita UART2
}

int UART2_Write(int ch) {
    while (!(USART2->SR & USART_SR_TXE)); // Attendi finché il registro di trasmissione è vuoto
    USART2->DR = (ch & 0xFF);
    return ch;
}

int UART2_Read(void) {
    while (!(USART2->SR & USART_SR_RXNE)); // Attendi finché il registro di ricezione non contiene dati
    return USART2->DR & 0xFF;
}

int __io_putchar(int ch) {
    return UART2_Write(ch);
}

int __io_getchar(void) {
    return UART2_Read();
}



