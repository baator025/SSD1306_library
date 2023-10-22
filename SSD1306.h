/**
 * Header file for SSD1306 library for multiple MCUs. In order to keep backwards compatibility
 * for the platform that the library was designed for, some parts of platform-specific implementation
 * have to stay in code.
 * In case of adding similar pieces of code in the future, remember to guard them in preprocessors
 * conditions. Platform shall be defined in low level API file.
**/

#ifndef SSD1306_H
#define SSD1306_H

#include<stdlib.h>

#include "SSD1306_platforms_config.h"
#include "ssd1306_low_level_api.h"
#include "SSD1306_commands.h"

//font headers:
#include "fonts/Verdana_7.h"
#include "fonts/Verdana_11.h"

//address of ssd1306 display on i2c bus
#define DSPL_ADDR 0x3c                  //I2C address of a display

//functions prototypes:
void SSD1306_init(uint8_t height);
uint8_t draw_line();
void write_field(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix,
                    uint8_t* data, uint16_t length);
void clear_display(void);
void print(char* string, uint8_t length, uint8_t start_x, uint8_t start_y);
void write_field_flash(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix,
                    const MEMORY_PREFIX uint8_t* data, uint16_t data_length);
void print_big(char* string, uint8_t length, uint8_t start_x, uint8_t start_y);

#endif //SSD106_H