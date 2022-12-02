#include "gpio.h"
#include "platform.h"

void gpio_pinmode(uint8_t pin, PinDir dir)
{
    uint32_t ddr=0;

    if(pin >= 0 && pin <= 7) 
        ddr = REG_DDRD;
    else if (pin >= 8 && pin <=13)
        ddr = REG_DDRB;
    else if (pin >= 14 && pin <=19)
        ddr = REG_DDRC;
    

    // ddr = 

}

void gpio_write(uint8_t pin, PinVal val)
{}

PinVal gpio_read(uint8_t pin)
{}
