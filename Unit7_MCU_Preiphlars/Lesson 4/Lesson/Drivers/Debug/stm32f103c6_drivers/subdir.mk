################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_drivers/stm32f103c6_EXTI_driver.c \
../stm32f103c6_drivers/stm32f103c6_GPIO_driver.c 

OBJS += \
./stm32f103c6_drivers/stm32f103c6_EXTI_driver.o \
./stm32f103c6_drivers/stm32f103c6_GPIO_driver.o 

C_DEPS += \
./stm32f103c6_drivers/stm32f103c6_EXTI_driver.d \
./stm32f103c6_drivers/stm32f103c6_GPIO_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_drivers/stm32f103c6_EXTI_driver.o: ../stm32f103c6_drivers/stm32f103c6_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded Systems/workspace/Drivers/stm32f103c6_drivers/inc" -I"D:/Embedded Systems/workspace/Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32f103c6_GPIO_driver.o: ../stm32f103c6_drivers/stm32f103c6_GPIO_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Embedded Systems/workspace/Drivers/stm32f103c6_drivers/inc" -I"D:/Embedded Systems/workspace/Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

