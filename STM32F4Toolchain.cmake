include(CMakeForceCompiler)

set(MCU_ARCH cortex-m4)
set(MCU_FLOAT_ABI hard)
set(MCU "-mcpu=${MCU_ARCH} -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=${MCU_FLOAT_ABI}")

set(GCC_ARM_BIN_DIR /home/lee/Downloads/gcc-arm-none-eabi-7-2018-q2-update/bin)

set(CMAKE_C_COMPILER ${GCC_ARM_BIN_DIR}/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${GCC_ARM_BIN_DIR}/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER "${GCC_ARM_BIN_DIR}/arm-none-eabi-gcc")

set(COMMON_FLAGS "${MCU} -Wall -fdata-sections -ffunction-sections")

set(CMAKE_C_FLAGS ${COMMON_FLAGS})
set(CMAKE_CXX_FLAGS ${COMMON_FLAGS})
set(CMAKE_ASM_FLAGS "-x assembler-with-cpp ${COMMON_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${MCU} -specs=nano.specs -Wl,-gc-sections -T ${CMAKE_SOURCE_DIR}/STM32F446RETx_FLASH.ld -Wl,-Map=blah.map,--cref")