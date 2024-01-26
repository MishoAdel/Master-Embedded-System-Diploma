################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/keypad.c \
../HAL/lcd.c \
../HAL/seven_seg.c 

OBJS += \
./HAL/keypad.o \
./HAL/lcd.o \
./HAL/seven_seg.o 

C_DEPS += \
./HAL/keypad.d \
./HAL/lcd.d \
./HAL/seven_seg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/keypad.o: ../HAL/keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded Systems/workspace/Drivers/stm32f103c6_drivers/inc" -I"D:/Embedded Systems/workspace/Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/lcd.o: ../HAL/lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded Systems/workspace/Drivers/stm32f103c6_drivers/inc" -I"D:/Embedded Systems/workspace/Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/seven_seg.o: ../HAL/seven_seg.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded Systems/workspace/Drivers/stm32f103c6_drivers/inc" -I"D:/Embedded Systems/workspace/Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/seven_seg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

