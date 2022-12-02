include ../mk/common.mk
include ../mk/toolchain.mk

ARCH:= -mmcu=atmega328p
CFLAGS:= -Os -DF_CPU=16000000UL -I include
LFLAGS:= -L ../metal -lmetal

# C source files
CSRCS:= 

# Asm source files
SSRCS:= 

# executable name
EXEC:= 

HEX?=0
DBG?=0

ifneq (DBG, 0)
	CFLAGS += -g -DDEBUG_LEVEL=$(DBG)
endif

OBJS := $(patsubst %.S, %.o, $(CSRCS))
OBJS += $(patsubst %.s, %.o, $(CSRCS))
OBJS += $(patsubst %.c, %.o, $(CSRCS))

default: $(EXEC)


$(EXEC): $(OBJS)
	@echo "$@"
# $(CC) $(ARCH) -o $@ $^ $(LFLAGS)


%.o: %.c
	@printf "$(CLR_CY)> Compiling [$@ <- $^] $(CLR_NC)\n"
	$(CC) $(ARCH) $(CFLAGS) -c -o $@ $^


%.elf: %.o
	@printf "$(CLR_CY)> Linking [$@ <- $^] $(CLR_NC)\n"
	$(CC) $(ARCH) $(CFLAGS) -c -o $@ $^


.PHONY: clean
clean:
	rm -f *.o *.hex *.bin