################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Utils/global.c \
../Core/Src/Utils/mainloop.c 

OBJS += \
./Core/Src/Utils/global.o \
./Core/Src/Utils/mainloop.o 

C_DEPS += \
./Core/Src/Utils/global.d \
./Core/Src/Utils/mainloop.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Utils/%.o Core/Src/Utils/%.su Core/Src/Utils/%.cyclo: ../Core/Src/Utils/%.c Core/Src/Utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G491xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Utils

clean-Core-2f-Src-2f-Utils:
	-$(RM) ./Core/Src/Utils/global.cyclo ./Core/Src/Utils/global.d ./Core/Src/Utils/global.o ./Core/Src/Utils/global.su ./Core/Src/Utils/mainloop.cyclo ./Core/Src/Utils/mainloop.d ./Core/Src/Utils/mainloop.o ./Core/Src/Utils/mainloop.su

.PHONY: clean-Core-2f-Src-2f-Utils

