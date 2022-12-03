#include "gpio.h"
#include "platform.h"
#include "bitmanip.h"
#include "mmio.h"

void gpio_pinmode(uint8_t pin, PinDir dir)
{
    uintptr_t ddr=0; int offset;
    if(pin >= 0 && pin <= 7) {
        ddr = REG_DDRD;
        offset = 0;
    }
    else if (pin >= 8 && pin <=13) {
        ddr = REG_DDRB;
        offset = 8;
    }
    else if (pin >= 14 && pin <=19) {
        ddr = REG_DDRC;
        offset = 14;
    }
    uint8_t ddrv = REG8(ddr);
    ddrv = (dir == OUTPUT) ? bitset(ddrv, pin-offset): bitclear(ddrv, pin-offset);
    REG8(ddr) = ddrv;
}

void gpio_write(uint8_t pin, PinVal val)
{
    uintptr_t port=0; int offset;
    if(pin >= 0 && pin <= 7) {
        port = REG_PORTD;
        offset = 0;
    }
    else if (pin >= 8 && pin <=13) {
        port = REG_PORTB;
        offset = 8;
    }
    else if (pin >= 14 && pin <=19) {
        port = REG_PORTC;
        offset = 14;
    }
    uint8_t portv = REG8(port);
    REG8(port) = (val == HIGH) ? bitset(portv, pin-offset): bitclear(portv, pin-offset);
}

PinVal gpio_read(uint8_t pin)
{}
