#include "uart.h"
#include "time.h"

void putstr(char *c)
{
    while(*c)
    {
        if(*c=='\n')
            uart_putchar('\r');
        uart_putchar(*(c++));
    }
}

int main()
{
    uart_init(UART_DIV_9600);
    while(1)
    {
        putstr("Hello World!");
        msleep(1000);
    }
}