//Add font by including header file. Header file, besides definitions, should contain font macros
//All fonts and bitmaps should be written in progmem

#include<avr/io.h>
#include"SSD1306.h"
#define LED PB5
#include <util/delay.h>

void blink1(void){
    DDRB |= (1 << LED);

    PORTB |= (1 << LED);
    _delay_ms(125);
    PORTB &= ~(1 << LED);
    _delay_ms(125);
    PORTB |= (1 << LED);
    _delay_ms(1500);
    PORTB &= ~(1 << LED);
}


void SSD1306_init(uint8_t height){

    uint8_t init_sequence[24] = {CMD_CHAIN, DSPL_OFF, SET_OSC_FREQ, OSC_FREQ, 
                                SET_MUX_RATIO, MUX_RATIO_32, SET_DSPL_OFFSET, DSPL_OFFSET,
                                DSPL_START_LINE, CHRG_PMP_SETTING, CHRG_PMP_ON, SGMT_REMAP, 
                                COM_OUTPT_SCAN_DIR, SET_COM_HW_CONF, SET_CONTRAST, CONTRAST, 
                                SET_PRECHRG_PERIOD, PRECHRG_PERIOD, SET_VCOMH_DSLCT_VAL, VCOMH_DSLCT_VAL,
                                DISABLE_ENTIRE_DPSL_ON, SET_NRML_DSPL, SCROLL_DEACTIV, DSPL_ON};

    i2c_send_chunk(DSPL_ADDR, sizeof(init_sequence), init_sequence);
}

//this function with handle situation, in which bitmap needs to be written from any starting point
//which doesn't need to be also a starting point of a page. Function expects bitmap encoded in bytes 
//corresponding to pages. Function doesn't handle parsing fonts or any other bitmaps to expected format  

void write_field(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix, 
                    uint8_t* data, uint16_t data_length){

    uint8_t size_y = size_y_pix/8; 
    uint8_t start_y;
    uint8_t offset = start_y_pix%8; 
    uint8_t offset_mask_MS = 0x80;
    uint8_t pwr;

    if(start_y_pix%8 == 0){                 //compensate if start point is in a middle of a page
        start_y = start_y_pix/8;
    } else{
        start_y = (start_y_pix/8);
        size_y += 1;
        for(pwr = 1; pwr < offset; pwr++){  //define offset mask
            offset_mask_MS = offset_mask_MS|(offset_mask_MS>>1);
        }
    }
    
    uint8_t addressing_mode[3] = {CMD_CHAIN, SET_ADDR_MODE, HORIZONTAL_ADDR_MODE};
    i2c_send_chunk(DSPL_ADDR, sizeof(addressing_mode), addressing_mode);

    //no idea why one needs to be subtracted from x size
    uint8_t field_definition[7] = {CMD_CHAIN, SET_COLUMN_START_END, start_x, start_x+size_x-1,
                                    SET_PAGE_START_END, start_y, start_y+size_y};
    i2c_send_chunk(DSPL_ADDR, sizeof(field_definition), field_definition);
  
    uint16_t length = (size_x * size_y) + 1;
    uint8_t buffer[length];
    buffer[0] = DATA_CHAIN;

    uint16_t i;
    uint8_t page = 1;
    for(i = 1; i<sizeof(buffer); i++){
        buffer[i] = 0;
    }

    for(i = 0; i<data_length; i++){  
            buffer[i+1] |= ((*(data + i))<<offset);  
            buffer[i+size_x+1] |= ((*(data+i)&offset_mask_MS)>>(8-offset));
            if(i%(size_x-1) == 0 && i != 0) page++;
    }

    i2c_send_chunk(DSPL_ADDR, sizeof(buffer), buffer);
}


void clear_display(void){
    uint8_t addressing_mode[3] = {CMD_CHAIN, SET_ADDR_MODE, HORIZONTAL_ADDR_MODE};
    i2c_send_chunk(DSPL_ADDR, sizeof(addressing_mode), addressing_mode);

    uint8_t field_definition[7] = {CMD_CHAIN, SET_COLUMN_START_END, 0, 127,
                                    SET_PAGE_START_END, 0, 4};
    i2c_send_chunk(DSPL_ADDR, sizeof(field_definition), field_definition);

    uint8_t display_command[2];
    display_command[0] = CMD_CHAIN;
    display_command[1] = DSPL_OFF;
    i2c_send_chunk(DSPL_ADDR, sizeof(display_command), display_command);

    uint16_t i; 
    i2c_send_start();
    i2c_send_address(DSPL_ADDR, 'w');
    i2c_send_byte(DATA_CHAIN);
    for(i = 0; i < 512; i++){
        i2c_send_byte(0);
    }
    i2c_send_stop();

    display_command[0] = CMD_CHAIN;
    display_command[1] = DSPL_ON;
    i2c_send_chunk(DSPL_ADDR, sizeof(display_command), display_command);
}


void print(char* string, uint8_t length, uint8_t start_x, uint8_t start_y){
    uart_init(9600);
    uint8_t i;
    uint8_t x = start_x;
    uint8_t y = start_y;
    uint8_t spacing = 1;

    uint8_t index;
    uint16_t byte_offset_start;
    uint16_t sign_width;
    uint16_t sign_size;
    uint16_t sign_height;
    uint8_t sign_vertical_offset;
    uint16_t buffer_length;

    for(i=0; i<(length-1); i++){
        if((uint8_t) *(string+i) < 32){
        break;
        }

        if(*(string+i) < 'V'){
            index = (uint8_t)* (string+i) - 32;
            byte_offset_start = pgm_read_byte(&FONT_DESCRIPTORS_1[index][2]);
            sign_width = pgm_read_byte(&FONT_DESCRIPTORS_1[index][0]); 
            sign_size = sign_width;
            sign_height = pgm_read_byte(&FONT_DESCRIPTORS_1[index][1]);
            if(sign_height%8!=0){
                sign_height = ((sign_height/8)+1)*8;
            }
            sign_vertical_offset = pgm_read_byte(&FONT_DESCRIPTORS_1[index][3]);

            buffer_length = sign_width*(sign_height/8);
        } else{
            index = (uint8_t)* (string+i) - 32 - 54;
            byte_offset_start = pgm_read_byte(&FONT_DESCRIPTORS_2[index][2]);
            sign_width = pgm_read_byte(&FONT_DESCRIPTORS_2[index][0]); 
            sign_size = sign_width;
            sign_height = pgm_read_byte(&FONT_DESCRIPTORS_2[index][1]);
            if(sign_height%8!=0){
                sign_height = ((sign_height/8)+1)*8;
            }
            sign_vertical_offset = pgm_read_byte(&FONT_DESCRIPTORS_2[index][3]);
            send_frame(*(string+i));
            send_frame(sign_size);
            buffer_length = sign_width*(sign_height/8);
        } 

        uint8_t buffer[buffer_length];
        uint8_t j;
        if(*(string+i) < 'V'){
            for(j = 0; j < sign_size; j++){
                *(buffer+j) = pgm_read_byte(&FONT_BITMAPS_1[byte_offset_start+j]);
            }
        }else{
            for(j = 0; j < sign_size; j++){
                *(buffer+j) = pgm_read_byte(&FONT_BITMAPS_2[byte_offset_start+j]);
            }    
        }
    

        // if(*(string+i) == 'V'){
        //     uint8_t dupa = (uint8_t)* (string+i) - 32;
        //     uint8_t dupa2 = pgm_read_word(&FONT_DESCRIPTORS[dupa+1][2]) - pgm_read_word(&FONT_DESCRIPTORS[dupa][2]);
        //     uart_init(9600);
        //     send_frame(pgm_read_byte(&FONT_DESCRIPTORS[dupa][2]));
        //     send_frame(dupa2);
        //     continue;
        // }


        // uint16_t byte_offset_start = *(*(verdana_7ptDescriptors+index)+2);
        // if(*(string+i) == '~'){
        //     sign_size = sign_width;
        //     // sign_size = *(*(verdana_7ptDescriptors+index)+0);
        // } else{
        //     sign_size = pgm_read_word(&FONT_DESCRIPTORS[index+1][2]) - pgm_read_word(&FONT_DESCRIPTORS[index][2]);
        //     // sign_size = *(*(verdana_7ptDescriptors+index+1)+2) - *(*(verdana_7ptDescriptors+index)+2);
        // }            
        // send_frame(*(string+i));
        // send_frame(sign_size);
        
        // uint16_t sign_height = *(*(verdana_7ptDescriptors+index)+1);

        
        // uint16_t sign_width = *(*(verdana_7ptDescriptors+index)+0);

        write_field(x, y+sign_vertical_offset, sign_width, sign_height, buffer, buffer_length);
        x = x+sign_width+spacing;
    }
}