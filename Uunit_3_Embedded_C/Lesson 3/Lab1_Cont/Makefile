
CC=arm-non-eabi
CFLAGS=-g -mcpu=armej926-s
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS==$(wildcard *.s)
ASOBJ=$(ASS:.s=.o)
PRJ_NAME=assign

all:$(PRJ_NAME).bin
	@echo "________Build is done__________"

%.o : %.s
	$(CC)-as.exe $(CFLAGS) $< -o <@
	
%.o : %.c
	$(CC)-gcc.exe $(CFLAGS) $(INCS) -c $< -o <@
	
$(PRJ_NAME).elf : $(OBJ) $(ASOBJ)
	$(CC)-ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(ASOBJ) -o <@ -Map=Map_file.map
	
$(PRJ_NAME).bin : $(PRJ_NAME).elf
	$(CC)-objcopy.exe -O binary $< <@
	
clean:
	rm *.elf *.bin
	
clean_all:
	rm *.o *.elf *.bin