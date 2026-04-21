#include "stm32f4xx_hal.h"

UART_HandleTypeDef *console_io_uart_ptr = 0;

int __io_getchar(void) {
    if (console_io_uart_ptr) {
        unsigned char _char;

        HAL_UART_Receive(console_io_uart_ptr, &_char, 1, HAL_MAX_DELAY);
        HAL_UART_Transmit(console_io_uart_ptr, &_char, 1, HAL_MAX_DELAY);

        if (_char == '\r') {
            unsigned char repl = '\n';
            HAL_UART_Transmit(console_io_uart_ptr, &repl, 1, HAL_MAX_DELAY);
        }

        return _char;
    }

    return 0;
}
