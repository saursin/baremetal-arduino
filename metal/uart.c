#include "uart.h"
#include "mmio.h"
#include "bitmanip.h"
#include "platform.h"


void uart_init(uint16_t div)
{
    // set baud rate
    REG8(REG_UBRR0H) = (div >> 8) & 0xf;
    REG8(REG_UBRR0L) = div;

    // Enable Uart receiver and transmitter
    REG8(REG_UCSR0B) = (1<<4) | (1<<3);

    /* Set frame format: 8data, 2stop bit */
    REG8(REG_UCSR0C) = (1<<3) | (3 << 1);    
}

void uart_putchar(char c)
{
    /* Wait for empty transmit buffer */
    while (!(bitcheck(REG8(REG_UCSR0A), 5)))
    ;
    /* Put data into buffer, sends the data */
    REG8(REG_UDR0) = c;
}

char uart_getchar()
{
    /* Wait for data to be received */
    while (!(bitcheck(REG8(REG_UCSR0A), 7)))
    ;
    
    /* Get and return received data from buffer */
    return REG8(REG_UDR0);
}