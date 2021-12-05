#include<avr/io.h>
#include"uart.h"
#include"i2c.h"
#include"SSD1306.h"
#include"Verdana_7.h"


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
    
    uint8_t size_y; //= size_y_pix/8;
    uint8_t start_y;
    uint8_t offset = start_y_pix%8; 
    uint8_t offset_mask_MS = 0x80;
    uint8_t offset_mask_LS;
    uint8_t pwr;
    uart_init(9600);
    send_frame(offset);
    if(size_y_pix%8 == 0){                  //compensate if size is bigger than a page
        size_y = size_y_pix/8;
    } else{
        size_y = (size_y_pix/8)+1;
    }

    if(start_y_pix%8 == 0){                 //compensate if start point is in a middle of a page
        start_y = start_y_pix/8;
    } else{
        start_y = (start_y_pix/8);
        size_y += 1;
        for(pwr = 1; pwr < offset; pwr++){  //define offset mask
            offset_mask_MS = offset_mask_MS|(offset_mask_MS>>1);
        }
    }
    offset_mask_LS = offset_mask_MS>>(8-offset);

    send_frame('a');
    send_frame(offset_mask_MS);
    send_frame('a');
    send_frame(offset_mask_LS);
    
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

void print(char* string, uint8_t length){
    uint8_t i;
    for(i=0; i<length; i++){
        uint8_t index = (uint8_t) *(string+i) - 32;

        uint16_t byte_offset_start = *(*(verdana_7ptDescriptors+index)+2);
        uint16_t sign_size = *(*(verdana_7ptDescriptors+index+1)+2) - *(*(verdana_7ptDescriptors+index)+2);
        uint16_t sign_height = *(*(verdana_7ptDescriptors+index)+1);
        if(sign_height < 8) sign_height = 8;
        uint16_t sign_width = *(*(verdana_7ptDescriptors+index)+0);

        uint16_t buffer_length;
        if(sign_height%8 == 0){
            buffer_length = sign_width*(sign_height/8);
        }else{ 
            buffer_length = sign_width*(sign_height/8)+1; 
        }
        uint8_t buffer[buffer_length];
        uint8_t j;
        for(j = 0; j < sign_size; j++){
            *(buffer+j) = *(verdana_7ptBitmaps+byte_offset_start+j);
        }

        write_field(6*i, 0, sign_width, sign_height, buffer, buffer_length);
    }
}