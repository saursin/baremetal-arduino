#include "stdio.h"
#include "uart.h"
#include "time.h"

int main()
{
    uart_init(UART_DIV_9600);   
    while(1)
    {
        char bf[100];
        gets(bf, 100, true, "> ");
        puts("\ngot: ");puts(bf);putchar('\n');
        msleep(1000);
    }
}