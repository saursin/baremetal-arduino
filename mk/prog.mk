PORT:= /dev/ttyACM0
BAUD:= 115200

IMG_HEX:= $(EXEC:.elf=.hex)

.PHONY: prog
prog: $(IMG_HEX)
	avrdude -F -V -c arduino -p ATMEGA328P -P $(PORT) -b $(BAUD) -U flash:w:$(IMG_HEX)

$(IMG_HEX): $(EXEC)
	@printf "$(CLR_CY)> Converting to hex [$@ <- $^] $(CLR_NC)"
	$(OC) -O ihex -R .eeprom $^ $@
