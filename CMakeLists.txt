cmake_minimum_required(VERSION 3.12)
set(CMAKE_C_STANDARD 11)

#location of source file:
set(LOW_LEVEL_IMP "i2c_examples/ssd1306_i2c_api.c")

add_library(ssd1306
                SSD1306.c
                ${LOW_LEVEL_IMP}
                fonts/Verdana_7.c
                fonts/Verdana_11.c)

#include platform specific libraries if necessary:
target_link_libraries(ssd1306
                        pico_stdlib
                        hardware_pio)
