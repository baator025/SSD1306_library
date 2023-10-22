#include "SSD1306.h"

void SSD1306_init(uint8_t height){

    uint8_t mux_ratio = height-1;

    uint8_t init_sequence[24] = {CMD_CHAIN, DSPL_OFF, SET_OSC_FREQ, OSC_FREQ,
                                SET_MUX_RATIO, mux_ratio, SET_DSPL_OFFSET, DSPL_OFFSET,
                                DSPL_START_LINE, CHRG_PMP_SETTING, CHRG_PMP_ON, SGMT_REMAP,
                                COM_OUTPT_SCAN_DIR, SET_COM_HW_CONF, SET_CONTRAST, CONTRAST,
                                SET_PRECHRG_PERIOD, PRECHRG_PERIOD, SET_VCOMH_DSLCT_VAL, VCOMH_DSLCT_VAL,
                                DISABLE_ENTIRE_DPSL_ON, SET_NRML_DSPL, SCROLL_DEACTIV, DSPL_ON};

    i2c_send_chunk(DSPL_ADDR, sizeof(init_sequence), init_sequence);
}


//this function with handle situation, in which bitmap needs to be written from any starting point
//which doesn't need to be also a starting point of a page. Function expects bitmap encoded in bytes
//corresponding to pages.

void write_field(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix,
                    uint8_t* data, uint16_t data_length){

    uint8_t size_y = size_y_pix/8;
    uint8_t start_y;
    uint8_t offset = start_y_pix%8;
    uint8_t offset_mask = 0x80;
    uint8_t pwr;

    if(start_y_pix%8 == 0){                 //compensate if start point is in a middle of a page
        start_y = start_y_pix/8;
    } else{
        start_y = (start_y_pix/8);
        size_y += 1;
        for(pwr = 1; pwr < offset; pwr++){  //define offset mask
            offset_mask = offset_mask|(offset_mask>>1);
        }
    }

    //define borders of field on SSD1306
    uint8_t addressing_mode[3] = {CMD_CHAIN, SET_ADDR_MODE, HORIZONTAL_ADDR_MODE};
    i2c_send_chunk(DSPL_ADDR, sizeof(addressing_mode), addressing_mode);

    uint8_t field_definition[7] = {CMD_CHAIN, SET_COLUMN_START_END, start_x, start_x+size_x-1,
                                    SET_PAGE_START_END, start_y, start_y+size_y};
    i2c_send_chunk(DSPL_ADDR, sizeof(field_definition), field_definition);

    //create a buffer for a bitmap in order to add command and offset the data if necessary:
    uint16_t length = (size_x * size_y) + 1;
    uint8_t buffer[length];
    buffer[0] = DATA_CHAIN;
    uint16_t i;
    uint8_t page = 1;
    for(i = 1; i<sizeof(buffer); i++){
        buffer[i] = 0;
    }

    //algorithm offseting the bitmap, if first pixel of a bitmap is in a middle of SSD1306's page
    for(i = 0; i<data_length; i++){
            buffer[i+1] |= ((*(data + i))<<offset);
            buffer[i+size_x+1] |= ((*(data+i)&offset_mask)>>(8-offset));
            if(i%(size_x-1) == 0 && i != 0) page++;
    }

    //write bitmap to display
    i2c_send_chunk(DSPL_ADDR, sizeof(buffer), buffer);
}


//variant of write field, which can be used for printing bitmaps from flash memory

void write_field_flash(uint8_t start_x, uint8_t start_y_pix, uint8_t size_x, uint8_t size_y_pix,
                    const MEMORY_PREFIX uint8_t* data, uint16_t data_length){

    uint8_t size_y = size_y_pix/8;
    uint8_t start_y;
    uint8_t offset = start_y_pix%8;
    uint8_t offset_mask = 0x80;
    uint8_t pwr;

    if(start_y_pix%8 == 0){                 //compensate if start point is in a middle of a page
        start_y = start_y_pix/8;
    } else{
        start_y = (start_y_pix/8);
        size_y += 1;
        for(pwr = 1; pwr < offset; pwr++){  //define offset mask
            offset_mask = offset_mask|(offset_mask>>1);
        }
    }

    //define borders of field on SSD1306
    uint8_t addressing_mode[3] = {CMD_CHAIN, SET_ADDR_MODE, HORIZONTAL_ADDR_MODE};
    i2c_send_chunk(DSPL_ADDR, sizeof(addressing_mode), addressing_mode);

    uint8_t field_definition[7] = {CMD_CHAIN, SET_COLUMN_START_END, start_x, start_x+size_x-1,
                                    SET_PAGE_START_END, start_y, start_y+size_y};
    i2c_send_chunk(DSPL_ADDR, sizeof(field_definition), field_definition);

    //create a buffer for a bitmap in order to add command and offset the data if necessary:
    uint16_t length = (size_x * size_y) + 1;
    uint8_t buffer[length];
    buffer[0] = DATA_CHAIN;
    uint16_t i;
    uint8_t page = 1;
    for(i = 1; i<sizeof(buffer); i++){
        buffer[i] = 0;
    }

    //algorithm offseting the bitmap, if first pixel of a bitmap is in a middle of SSD1306's page
    for(i = 0; i<data_length; i++){
            buffer[i+1] |= ((*(data + i))<<offset);
            buffer[i+size_x+1] |= ((*(data+i)&offset_mask)>>(8-offset));
            if(i%(size_x-1) == 0 && i != 0) page++;
    }

    //write bitmap to display
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

    uint8_t empty_page_val = 0;
    #ifdef LOW_LEVEL_I2C_ACCESS
    uint16_t i;
    i2c_send_start();
    i2c_send_address(DSPL_ADDR, 'w');
    i2c_send_byte(DATA_CHAIN);
    for(i = 0; i < 512; i++){
        i2c_send_byte(empty_page_val);
    }
    i2c_send_stop();
    #else
    uint16_t page_counter;
    for(page_counter = 0; page_counter < 512; page_counter++){
        i2c_send_chunk(DSPL_ADDR, sizeof(empty_page_val), &empty_page_val);
    }
    #endif


    display_command[0] = CMD_CHAIN;
    display_command[1] = DSPL_ON;
    i2c_send_chunk(DSPL_ADDR, sizeof(display_command), display_command);
}


void print(char* string, uint8_t length, uint8_t start_x, uint8_t start_y){
    uint8_t i;
    uint8_t x = start_x;
    uint8_t y = start_y;
    uint8_t spacing = 1;                                          //space between the characters in pixels

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

        //extract glyph dimensions and offsets:
        index = (uint8_t)* (string+i) - 32;
        byte_offset_start = verdana_7ptDescriptors[index][2];               //descriptor array name
        sign_width = verdana_7ptDescriptors[index][0];                      //descriptor array name
        sign_height = verdana_7ptDescriptors[index][1];                     //descriptor array name
        if(sign_height%8!=0){
            sign_size = ((sign_height/8)+1)*sign_width;
            sign_height = ((sign_height/8)+1)*8;
        } else{
            sign_size = (sign_height/8)*sign_width;
        }
        sign_vertical_offset = verdana_7ptDescriptors[index][3];            //descriptor array name

        //extract glyph bitmap and save it in a buffer:
        buffer_length = sign_width*(sign_height/8);
        uint8_t buffer[buffer_length];
        uint8_t j;
        for(j = 0; j < sign_size; j++){
            *(buffer+j) = verdana_7ptBitmaps[byte_offset_start+j];          //bitmap array name
        }

        //print a buffer:
        write_field(x, y+sign_vertical_offset, sign_width, sign_height, buffer, buffer_length);
        x = x+sign_width+spacing;
    }
}


void print_big(char* string, uint8_t length, uint8_t start_x, uint8_t start_y){
    uint8_t i;
    uint8_t x = start_x;
    uint8_t y = start_y;
    uint8_t spacing = 1;                                          //space between the characters in pixels

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

        //extract glyph dimensions and offsets:
        index = (uint8_t)* (string+i) - 32;
        byte_offset_start = verdana_11ptDescriptors[index][2];               //descriptor array name
        sign_width = verdana_11ptDescriptors[index][0];                      //descriptor array name
        sign_height = verdana_11ptDescriptors[index][1];                     //descriptor array name
        if(sign_height%8!=0){
            sign_size = ((sign_height/8)+1)*sign_width;
            sign_height = ((sign_height/8)+1)*8;
        } else{
            sign_size = (sign_height/8)*sign_width;
        }
        sign_vertical_offset = verdana_11ptDescriptors[index][3];            //descriptor array name

        //extract glyph bitmap and save it in a buffer:
        buffer_length = sign_width*(sign_height/8);
        uint8_t buffer[buffer_length];
        uint8_t j;
        for(j = 0; j < sign_size; j++){
            *(buffer+j) = verdana_11ptBitmaps[byte_offset_start+j];          //bitmap array name
        }

        //print a buffer:
        write_field(x, y+sign_vertical_offset, sign_width, sign_height, buffer, buffer_length);
        x = x+sign_width+spacing;
    }
}