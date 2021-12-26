#ifndef SSD1306_H
#define SSD1306_H

#include<avr/io.h>
#include<stdlib.h>
#include"i2c.h"
#include"fonts/Verdana_7.h"
#include"fonts/Verdana_11.h"

//macros for SSD1306 commands

#define DSPL_ADDR 0x3c                  //I2C address of a display

//macros for core command codes for SSD1306 initialisation

#define CMD_CHAIN 0x00
#define DATA_CHAIN 0x40

#define DSPL_OFF 0xAE
#define DSPL_ON 0xAF

#define SET_OSC_FREQ 0xD5
#define OSC_FREQ 0x80

#define SET_MUX_RATIO 0xA8

#define SET_DSPL_OFFSET 0xD3
#define DSPL_OFFSET 0x00
#define DSPL_START_LINE 0x40

#define CHRG_PMP_SETTING 0x8D
#define CHRG_PMP_ON 0x14

#define SGMT_REMAP 0xA1 

#define COM_OUTPT_SCAN_DIR 0xC8

#define SET_COM_HW_CONF 0xDA
#define COM_HW_CONF 0X02

#define SET_CONTRAST 0x81
#define CONTRAST 0x8F

#define SET_PRECHRG_PERIOD 0xD9
#define PRECHRG_PERIOD 0xF1

#define SET_VCOMH_DSLCT_VAL 0x2E
#define VCOMH_DSLCT_VAL 0x40

#define ENTIRE_DSPL_ON 0xA5
#define DISABLE_ENTIRE_DPSL_ON 0xA4

#define SET_NRML_DSPL 0xA6

#define SCROLL_DEACTIV 0x2E

//utility command codes for SSD1306 

#define SET_ADDR_MODE 0x20
#define HORIZONTAL_ADDR_MODE 0x00
#define VERTICAL_ADDR_MODE 0x01
#define PAGE_ADDR_MODE 0x02

#define SET_COLUMN_START_END 0x21
#define SET_PAGE_START_END 0x22


void SSD1306_init(uint8_t height);
uint8_t draw_line();
void write_field(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix, 
                    uint8_t* data, uint16_t length);
void clear_display(void);
void print(char* string, uint8_t length, uint8_t start_x, uint8_t start_y);
void write_field_flash(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix, 
                    const __flash uint8_t* data, uint16_t data_length);
void print_big(char* string, uint8_t length, uint8_t start_x, uint8_t start_y);

#endif //SSD106_H