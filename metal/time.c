#include "time.h"

#define DELAY_PRESCALAR 260

void msleep(uint64_t t)
{
    uint64_t k = t * DELAY_PRESCALAR;
    while(k--){
        asm volatile("nop");
    }
}
