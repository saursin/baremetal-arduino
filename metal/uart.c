#include "uart.h"
#include "mmio.h"
#include "platform.h"


void uart_init(uint16_t div)
{
    // set baud rate
    REG8(REG_UBRR0H) = (div >> 8) & 0xff;
    REG8(REG_UBRR0L) = div & 0xFF;

    // Enable Uart receiver and transmitter
    REG8(REG_UCSR0B) = (1<<4) | (1<<3);

    /* Set frame format: 8data, 2stop bit */
    REG8(REG_UCSR0C) = (1<<3) | (3 << 1);    
}

void uart_putchar(char c)
{
    /* Wait for empty transmit buffer */
    while (!(REG8(REG_UCSR0A) & ( 1 << 5)))
    ;
    /* Put data into buffer, sends the data */
    REG8(REG_UDR0) = c;
}