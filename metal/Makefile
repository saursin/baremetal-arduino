include ../mk/common.mk

ARCH:= -mmcu=atmega328p
CFLAGS:= -Os -DF_CPU=16000000UL -I include
LFLAGS:= 
OBJS:= gpio.o

.DEFAULT_GOAL= lib		## Alias for target lib


.PHONY: lib
lib: libmetal.a	## Build metal lib


libmetal.a: $(OBJS)
	@printf "$(CLR_CY)> Building Lib [$@ <- $^] $(CLR_NC)\n"
	ar rcs $@ $^
	@printf "$(CLR_CY)> Build finished! $(CLR_NC)\n"


%.o: %.c
	@printf "$(CLR_CY)> Compiling [$@ <- $^] $(CLR_NC)\n"
	avr-gcc $(ARCH) $(CFLAGS) -c -o $@ $^


.PHONY: clean
clean:			## Clean build files
	rm -f *.o *.a
