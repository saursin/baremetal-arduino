include ../mk/common.mk
include ../mk/toolchain.mk

$(shell mkdir -p build)

ARCH:= -mmcu=atmega328p
CFLAGS:= -Os -DF_CPU=16000000UL -I include -ffreestanding
LFLAGS:= 

SRCS:= $(sort $(wildcard *.c))
OBJS:= $(addprefix build/, $(SRCS:.c=.o))

.DEFAULT_GOAL= lib

.PHONY: lib
lib: build/libmetal.a	## Build metal lib


build/libmetal.a: $(OBJS)
	@printf "$(CLR_CY)> Building Lib [$@ <- $^] $(CLR_NC)\n"
	ar rcs $@ $^
	@printf "$(CLR_CY)> Build finished! $(CLR_NC)\n"


build/%.o: %.c
	@printf "$(CLR_CY)> Compiling [$@ <- $^] $(CLR_NC)\n"
	$(CC) $(ARCH) $(CFLAGS) -c -o $@ $^


.PHONY: clean
clean:			## Clean build files
	rm -f build/*
