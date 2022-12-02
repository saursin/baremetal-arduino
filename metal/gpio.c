#include "gpio.h"
#include "platform.h"

void gpio_pinmode(uint8_t pin, PinDir dir)
{
    uint32_t ddr_offset=0;

    if(pin >= 0 && pin <= 7) 
        ddr_offset = REG_OFFSET_DDRD;
    else if (pin >= 8 && pin <=13)
        ddr_offset = REG_OFFSET_DDRB;
    else if (pin >= 14 && pin <=19)
        ddr_offset = REG_OFFSET_DDRC;
    

    // ddr_offset = 

}

void gpio_write(uint8_t pin, PinVal val)
{}

PinVal gpio_read(uint8_t pin)
{}
