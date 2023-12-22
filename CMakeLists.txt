# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/jeffp/pico/pico-sdk")

set(PICO_BOARD pico CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

if (PICO_SDK_VERSION_STRING VERSION_LESS "1.4.0")
  message(FATAL_ERROR "Raspberry Pi Pico SDK version 1.4.0 (or later) required. Your version is ${PICO_SDK_VERSION_STRING}")
endif()

project(pokeyusb C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(pokeyusb)

target_sources(pokeyusb PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/hid_app.c
        ${CMAKE_CURRENT_LIST_DIR}/pokeyusb.c
)

pico_set_program_name(pokeyusb "pokeyusb")
pico_set_program_version(pokeyusb "0.1")

# specify interface for printf
pico_enable_stdio_uart(pokeyusb 1)
pico_enable_stdio_usb(pokeyusb 0)

# Add the standard library to the build
target_link_libraries(pokeyusb PUBLIC pico_stdlib hardware_dma hardware_pio tinyusb_host tinyusb_board)

# state machines
pico_generate_pio_header(pokeyusb ${CMAKE_CURRENT_LIST_DIR}/kbd.pio)

# Make sure TinyUSB can find tusb_config.h
# Add the standard include files to the build
target_include_directories(pokeyusb PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}
  ) #  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
#)

pico_add_extra_outputs(pokeyusb)

