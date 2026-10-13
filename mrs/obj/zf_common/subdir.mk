################################################################################
# MRS Version: 2.5.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_clock.c \
d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_debug.c \
d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_fifo.c \
d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_font.c \
d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_function.c \
d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_interrupt.c 

C_DEPS += \
./zf_common/zf_common_clock.d \
./zf_common/zf_common_debug.d \
./zf_common/zf_common_fifo.d \
./zf_common/zf_common_font.d \
./zf_common/zf_common_function.d \
./zf_common/zf_common_interrupt.d 

OBJS += \
./zf_common/zf_common_clock.o \
./zf_common/zf_common_debug.o \
./zf_common/zf_common_fifo.o \
./zf_common/zf_common_font.o \
./zf_common/zf_common_function.o \
./zf_common/zf_common_interrupt.o 

DIR_OBJS += \
./zf_common/*.o \

DIR_DEPS += \
./zf_common/*.d \

DIR_EXPANDS += \
./zf_common/*.234r.expand \


# Each subdirectory must supply rules for building sources it contributes
zf_common/zf_common_clock.o: d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_clock.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_debug.o: d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_debug.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_fifo.o: d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_fifo.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_font.o: d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_font.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_function.o: d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_function.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
zf_common/zf_common_interrupt.o: d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common/zf_common_interrupt.c
	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -fmax-errors=20 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall -g -I"d:/MRS_Projectt/CHV307_Library/Example/Libraries/doc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_components" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Core" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Ld" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Peripheral" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/sdk/Startup" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/user/inc" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_common" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_device" -I"d:/MRS_Projectt/CHV307_Library/Example/smart_car_round_01/code" -I"d:/MRS_Projectt/CHV307_Library/Example/libraries/zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

