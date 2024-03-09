cmake_minimum_required(VERSION 3.13)



# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(mt_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(motor_run
    motor_run.cpp
)

# enable usb output, disable uart output
pico_enable_stdio_usb(motor_run 1)
pico_enable_stdio_uart(motor_run 0)

add_library(pico_mcp4725 INTERFACE)

target_sources(pico_mcp4725 INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/mcp4725/mcp4725.cpp
  ${CMAKE_CURRENT_LIST_DIR}/src/mcp4725/mcp4725_Sinewave_Data.cpp
)

target_include_directories(pico_mcp4725 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)




# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(motor_run pico_stdlib hardware_i2c pico_mcp4725)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(motor_run)

