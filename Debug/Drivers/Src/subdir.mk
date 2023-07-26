################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/stmf411re_driver_GPIO.c \
../Drivers/Src/stmf411re_driver_I2C.c 

OBJS += \
./Drivers/Src/stmf411re_driver_GPIO.o \
./Drivers/Src/stmf411re_driver_I2C.o 

C_DEPS += \
./Drivers/Src/stmf411re_driver_GPIO.d \
./Drivers/Src/stmf411re_driver_I2C.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o Drivers/Src/%.su: ../Drivers/Src/%.c Drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -I"D:/Workspace/RTOSworkspace/FROM_Scratch/Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Src

clean-Drivers-2f-Src:
	-$(RM) ./Drivers/Src/stmf411re_driver_GPIO.d ./Drivers/Src/stmf411re_driver_GPIO.o ./Drivers/Src/stmf411re_driver_GPIO.su ./Drivers/Src/stmf411re_driver_I2C.d ./Drivers/Src/stmf411re_driver_I2C.o ./Drivers/Src/stmf411re_driver_I2C.su

.PHONY: clean-Drivers-2f-Src

