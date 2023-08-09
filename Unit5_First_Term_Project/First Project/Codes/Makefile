CC = arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
As_OBJ = $(As:.s=.o)
PRJ_NAME=pressure_controller

all:$(PRJ_NAME).bin
	@echo "________Build is done__________"

%.o : %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@

%.o : %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
$(PRJ_NAME).elf :$(OBJ) $(As_OBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(As_OBJ) -o $@ -Map=Map_file.map
	cp $(PRJ_NAME).elf $(PRJ_NAME).axf
	
$(PRJ_NAME).bin : $(PRJ_NAME).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean:
	rm *.elf *.bin
	
clean_all:
	rm *.o *.elf *.bin