#include "platform.h"
#include "mmio.h"
#include "gpio.h"
#include "uart.h"
#include "stdio.h"
#include "bitmanip.h"
#include "time.h"

int main()
{
    uart_init(UART_DIV_9600);
    puts("Running Blinky...");
    
    gpio_pinmode(13, OUTPUT);
    
    while(1)
    {
        gpio_write(13, HIGH);
        msleep(1000);
        gpio_write(13, LOW);
        msleep(1000);
    }
    return 0;
}