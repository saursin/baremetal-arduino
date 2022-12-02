# Toolchain prefix
TC_PREFIX:= avr

# Toolchain Path
TC_PATH:=

AS	:= $(TC_PREFIX)-as
AR	:= $(TC_PREFIX)-ar
CC	:= $(TC_PREFIX)-gcc
CCP	:= $(TC_PREFIX)-g++
LD	:= $(TC_PREFIX)-ld
OD	:= $(TC_PREFIX)-objdump
OC	:= $(TC_PREFIX)-objcopy