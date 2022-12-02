#include "gpio.h"
int delay(int a){}

int main()
{
    gpio_pinmode(13, OUTPUT);

    while(1){
        gpio_write(13, !gpio_read(13));
        delay(1000);
    }
    return 0;
}