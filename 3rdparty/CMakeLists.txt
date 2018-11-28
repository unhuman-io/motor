#file(DOWNLOAD "https://raw.githubusercontent.com/muflihun/easyloggingpp/v9.96.5/src/easylogging%2B%2B.h" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/easylogging++.h EXPECTED_MD5 10655cd1aabb3df9787dc63754636729)
#file(DOWNLOAD "https://raw.githubusercontent.com/muflihun/easyloggingpp/v9.96.5/src/easylogging%2B%2B.cc" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/easylogging++.cc EXPECTED_MD5 a8782ba880a51e34b69b93300c567099)

file(DOWNLOAD "https://gist.githubusercontent.com/kevinkreiser/39f2e39273c625d96790/raw/c5b9b40d1e47cd190d78582993fd07e4478540af/logging.hpp" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/logging.h EXPECTED_MD5 22c2a8f301ef87d2c1b28a760595ca37)
add_library(easylogging INTERFACE) #easylogging/easylogging++.cc
       # easylogging/easylogging++.h)
#add_library(easylogging easylogging/easylogging++.cc
 #           easylogging/easylogging++.h)
if(MCU_ARCH STREQUAL cortex-m4)
    target_include_directories(easylogging INTERFACE ${CMAKE_SOURCE_DIR}/src/hal_m4/st446)
else()
    target_include_directories(easylogging INTERFACE ${CMAKE_BINARY_DIR}/3rdparty/easylogging)
endif()

# Download just specific files as the repository is large
set(CMSIS "https://raw.githubusercontent.com/ARM-software/CMSIS_5/5.4.0/CMSIS/")
set(CMSIS_FILES core_cm4.h cmsis_version.h 
                cmsis_compiler.h cmsis_gcc.h
                mpu_armv7.h)
foreach(file ${CMSIS_FILES})
    file(DOWNLOAD "${CMSIS}/Core/Include/${file}" ${CMAKE_BINARY_DIR}/3rdparty/CMSIS/${file})
endforeach(file)
add_library(cmsis INTERFACE)
target_include_directories(cmsis INTERFACE ${CMAKE_BINARY_DIR}/3rdparty/CMSIS)