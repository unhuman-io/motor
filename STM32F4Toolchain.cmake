#include(CMakeForceCompiler)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING 1)
set(MCU_ARCH cortex-m4)
set(MCU_FLOAT_ABI hard)
set(MCU "-mcpu=${MCU_ARCH} -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=${MCU_FLOAT_ABI}")

find_path(GCC_ARM_BIN_DIR arm-none-eabi-gcc DOC "GCC arm bin directory")

set(CMAKE_C_COMPILER ${GCC_ARM_BIN_DIR}/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${GCC_ARM_BIN_DIR}/arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER "${GCC_ARM_BIN_DIR}/arm-none-eabi-gcc")

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

set(COMMON_FLAGS "${MCU} -Wall -fdata-sections -ffunction-sections")

set(CMAKE_C_FLAGS ${COMMON_FLAGS})
set(CMAKE_CXX_FLAGS ${COMMON_FLAGS})
set(CMAKE_ASM_FLAGS "-x assembler-with-cpp ${COMMON_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${MCU} -specs=nosys.specs -Wl,-gc-sections -Wl,-Map=blah.map,--cref")
# TODO: need option below?
#-T ${CMAKE_SOURCE_DIR}/src/hal_m4/st446/STM32F446RETx_FLASH.ld