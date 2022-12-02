#include "platform.h"
#include "mmio.h"
#include "gpio.h"
#include "bitmanip.h"
#include "time.h"

int main()
{
    // gpio_pinmode(13, OUTPUT);

    // while(1){
    //     gpio_write(13, !gpio_read(13));
    //     delay(1000);
    // }
    // return 0;

    /*Set to one the fifth bit of DDRB to one
    **Set digital pin 13 to output mode */
    REG8(REG_OFFSET_DDRB) = bitset(REG8(REG_OFFSET_DDRB), 5);

    while(1) {
        /*Set to one the fifth bit of PORTB to one
        **Set to HIGH the pin 13 */
        REG8(REG_OFFSET_PORTB) = bitset(REG8(REG_OFFSET_PORTB), 5);
        
        /*Wait 3000 ms */
        msleep(10);

        /*Set to zero the fifth bit of PORTB
        **Set to LOW the pin 13 */
        REG8(REG_OFFSET_PORTB) = bitclear(REG8(REG_OFFSET_PORTB), 5);

        /*Wait 3000 ms */
        msleep(10);
    }
}