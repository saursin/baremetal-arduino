#pragma once
#include <stdint.h>

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define UART_DIV_9600      F_CPU/16/9600-1
#define UART_DIV_115200    F_CPU/16/115200-1

void uart_init(uint16_t div);

void uart_putchar(char c);