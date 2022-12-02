# baremetal-arduino
baremetal-arduino 


## Installing AVR toolchain

```
sudo apt update
sudo apt install gcc-avr binutils-avr avr-libc gdb-avr avrdudr
```


## Arduino Pins & Ports
```
                  +-----___-----+
     Reset  PC6  =|1          28|=  PC5  A5
 [D0 (RX)]  PD0  =|2          27|=  PC4  A4
 [D1 (TX)]  PD1  =|3          26|=  PC3  A3
      [D2]  PD2  =|4          25|=  PC2  A2
    ~ [D3]  PD3  =|5          24|=  PC1  A1
      [D4]  PD4  =|6  Atmega  23|=  PC0  A0
                 =|7   328P   22|= 
                 =|8          21|= 
   Crystal  PB6  =|9          20|= 
   Crystal  PB7  =|10         19|=  PB5  [13] 
       [5]  PD5  =|11         18|=  PB4  [12]
       [6]  PD6  =|12         17|=  PB3  [11] ~
       [7]  PD7  =|13         16|=  PB2  [10] ~
       [8]  PB0  =|14         15|=  PB1  [ 9] ~
                  +-------------+ 

 ~ PWM enabled pins
```
* PC6: used for device reset
* PB6 & PB7: connected to oscillator
* Analog pins can also be used for digital IO


## Specs

* Flash: 32KB
* SRAM: 2KB
* EEPROM 1KB



## RAM Memory Map

```
Register space: 0x000 - 0x01F     0x20
I/O Space:      0x020 - 0x05F     0x40
SRAM Space:     0x060 - 0x7FF       

```