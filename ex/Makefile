include ../mk/common.mk
include ../mk/toolchain.mk

ex?=0
ifneq ($(MAKECMDGOALS),clean-all)
	ifeq ($(ex), 0)
        $(error No example specified)
	else
        include $(ex)/build.mk
	endif
endif

EXAMPLE_DIRS = $(sort $(dir $(wildcard */)))

CSRCS:= $(addprefix $(ex)/, $(CSRCS))
SSRCS:= $(addprefix $(ex)/, $(SSRCS))
EXEC:= 	$(addprefix $(ex)/, $(EXEC))

ARCH:= -mmcu=atmega328p
CFLAGS:= -Os -DF_CPU=16000000UL -I ../metal/include
LFLAGS:= -L ../metal/build -lmetal

HEX?=0
DBG?=0
OBJD?=0

ifneq (DBG, 0)
	CFLAGS += -g -DDEBUG_LEVEL=$(DBG)
endif

OBJS := $(CSRCS:.c=.o)
OBJS += $(SSRCS:.S=.o)

.DEFAULT_GOAL=$(EXEC)

$(EXEC): $(OBJS)
	@printf "$(CLR_CY)> Linking [$@ <- $^] $(CLR_NC)\n"
	$(CC) $(ARCH) -o $@ $^ $(LFLAGS)
ifneq ($(OBJD), 0)
	$(OD) -htd $@ > $@.objd.txt
endif

%.o: %.c
	@printf "$(CLR_CY)> Compiling [$@ <- $^] $(CLR_NC)\n"
	$(CC) $(ARCH) $(CFLAGS) -c -o $@ $^

%.o: %.S
	@printf "$(CLR_CY)> Compiling [$@ <- $^] $(CLR_NC)\n"
	$(CC) $(ARCH) $(CFLAGS) -c -o $@ $^

.PHONY: clean
clean:
	rm -f $(ex)/*.o $(ex)/*.hex $(ex)/*.elf $(ex)/*.objd.txt

.PHONY: clean-all
clean-all:
	@$(patsubst %/, make ex=% clean;, ${EXAMPLE_DIRS})

include ../mk/prog.mk