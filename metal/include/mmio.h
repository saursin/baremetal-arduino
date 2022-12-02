#pragma once
#include <stdint.h>

#define REG8(X)	    (*(volatile uint8_t *)(X))
#define REG16(X)	(*(volatile uint16_t *)(X))
#define REG32(X)	(*(volatile uint32_t *)(X))
#define REG64(X)	(*(volatile uint64_t *)(X))
