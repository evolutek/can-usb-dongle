################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/CanDriver/can_com.c \
../Core/Src/CanDriver/can_setup.c 

OBJS += \
./Core/Src/CanDriver/can_com.o \
./Core/Src/CanDriver/can_setup.o 

C_DEPS += \
./Core/Src/CanDriver/can_com.d \
./Core/Src/CanDriver/can_setup.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/CanDriver/%.o Core/Src/CanDriver/%.su Core/Src/CanDriver/%.cyclo: ../Core/Src/CanDriver/%.c Core/Src/CanDriver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G491xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-CanDriver

clean-Core-2f-Src-2f-CanDriver:
	-$(RM) ./Core/Src/CanDriver/can_com.cyclo ./Core/Src/CanDriver/can_com.d ./Core/Src/CanDriver/can_com.o ./Core/Src/CanDriver/can_com.su ./Core/Src/CanDriver/can_setup.cyclo ./Core/Src/CanDriver/can_setup.d ./Core/Src/CanDriver/can_setup.o ./Core/Src/CanDriver/can_setup.su

.PHONY: clean-Core-2f-Src-2f-CanDriver

