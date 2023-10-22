#ifndef SSD1306_I2C_H
#define SSD1306_I2C_H

#include "SSD1306_platforms_config.h"

uint8_t i2c_send_chunk(uint8_t address, uint16_t size, uint8_t* data);

#ifdef LOW_LEVEL_I2C_ACCESS
void i2c_send_start(void);
void i2c_send_stop(void);
void i2c_send_address(uint8_t address, char direction);
void i2c_send_byte(uint8_t data);
#endif //LOW_LEVEL_I2C_ACCESS

#endif //SSD1306_I2C_H