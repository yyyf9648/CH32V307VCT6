################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/src/isr.c \
d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/src/main.c 

C_DEPS += \
./user_c/isr.d \
./user_c/main.d 

OBJS += \
./user_c/isr.o \
./user_c/main.o 

DIR_OBJS += \
./user_c/*.o \

DIR_DEPS += \
./user_c/*.d \

DIR_EXPANDS += \
./user_c/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
user_c/isr.o: d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/src/isr.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
user_c/main.o: d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/src/main.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

