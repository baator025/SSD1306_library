#ifndef SSD1306_PLATFORM_CONFIG_H
#define SSD1306_PLATFORM_CONFIG_H

/*
 * Supported platform defines:
 */
#define RPI_PICO
// #define ATMEGA_328P

/*
 * Platform specific includes:
 */
#ifdef RPI_PICO
    #include "hardware/pio.h"
    #define MEMORY_PREFIX
#elif ATMEGA_328P
    #include <avr/io.h>
    #define MEMORY_PREFIX __flash
    #define LOW_LEVEL_I2C_ACCESS
#endif

#endif //SSD_PLATFORM_CONFIG_H
