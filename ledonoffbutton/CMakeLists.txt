cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(ledonoffbutton_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(
    ledonoffbutton
    ledonoffbutton.c
)
pico_enable_stdio_usb(ledonoffbutton 1)
pico_enable_stdio_uart(ledonoffbutton 1)
pico_add_extra_outputs(ledonoffbutton)
target_link_libraries(ledonoffbutton pico_stdlib)