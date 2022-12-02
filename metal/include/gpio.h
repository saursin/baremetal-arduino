#pragma once
#include <stdint.h>

typedef enum {
    LOW, HIGH
} PinVal;

typedef enum {
    INPUT, 
    OUTPUT
} PinDir;

void gpio_pinmode(uint8_t pin, PinDir dir);
void gpio_write(uint8_t pin, PinVal val);
PinVal gpio_read(uint8_t pin);
