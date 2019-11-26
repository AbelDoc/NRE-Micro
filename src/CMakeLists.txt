# Set a variable for commands below
set(PROJECT_NAME NRE-Micro)

# Define your project and language
project(${PROJECT_NAME})

# use this target for a quick compile-only check of your CPP files
# add more source (CPP) files here when you add them to the sketch
add_executable(NRE-Micro NRE-Micro.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set(ESP8266_LIB C:/Users/abell/Documents/ArduinoData/packages/esp8266/hardware/esp8266/2.5.0/libraries)
set(UNO_LIB C:/Users/abell/Documents/Arduino/libraries/)
set(ARDUINO_CMD arduino.exe)
SET(ARDUINO_PACKAGES C:/Users/abell/Documents/ArduinoData/packages)

SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)

set(CMAKE_C_COMPILER ${ARDUINO_PACKAGES}/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9/bin/xtensa-lx106-elf-gcc.exe)
set(CMAKE_CXX_COMPILER ${ARDUINO_PACKAGES}/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9/bin/xtensa-lx106-elf-g++.exe)

SET(COMMON_FLAGS "-c -w -Os -g -mlongcalls -mtext-section-literals -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -fno-exceptions")
SET(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -fpermissive -fno-threadsafe-statics")
SET(CMAKE_C_FLAGS "${COMMON_FLAGS} -fno-fat-lto-objects")

add_definitions(
        -DF_CPU=80000000L
        -DARDUINO=10810
        -DARDUINO_ESP8266_GENERIC
        -DARDUINO_ARCH_ESP8266
)

include_directories(
    ${ESP8266_LIB}/EEPROM
    ${ESP8266_LIB}/ESP8266WebServer/src
    ${ESP8266_LIB}/ESP8266WiFi/src
    ${ESP8266_LIB}/ESP8266HTTPUpdateServer/src
    ${UNO_LIB}/Adafruit_NeoPixel
    ${ARDUINO_PACKAGES}/esp8266/hardware/esp8266/2.5.0/cores/esp8266
    ${ARDUINO_PACKAGES}/esp8266/hardware/esp8266/2.5.0/variants/generic
    ${ARDUINO_PACKAGES}/esp8266/hardware/esp8266/2.5.0/tools/sdk/include
    ${ARDUINO_PACKAGES}/esp8266/hardware/esp8266/2.5.0/tools/sdk/lwip/include
    ${ARDUINO_PACKAGES}/esp8266/hardware/esp8266/2.5.0/tools/sdk/libc/xtensa-lx106-elf/include
)

# use the following two targets for building and uploading sketches from clion.
# select "verify" for just building, select "upload" for building and uploading.
# make sure you have selected the correct board and port in the arduino IDE before building this target!
# instead, you can also use --board and --port arguments here. for the m0, --board arduino:samd:mzero_bl
# see https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc for arduino cmd options
add_custom_target(upload ALL ${ARDUINO_CMD} --upload --preserve-temp-files --verbose NRE-Micro.cpp WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
add_custom_target(verify ALL ${ARDUINO_CMD} --verify --preserve-temp-files --verbose NRE-Micro.cpp WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})