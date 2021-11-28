#include<avr/io.h>
#include"uart.h"
#include"i2c.h"
#include"SSD1306.h"


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
    
    uint8_t size_y;
    uint8_t start_y;
    uint8_t offset = start_y_pix%8; 
    uint8_t offset_mask = 0x80;
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
            offset_mask = offset_mask|(offset_mask>>1);
        }
    }
    send_frame(offset_mask);
    uint8_t addressing_mode[3] = {CMD_CHAIN, SET_ADDR_MODE, HORIZONTAL_ADDR_MODE};
    i2c_send_chunk(DSPL_ADDR, sizeof(addressing_mode), addressing_mode);


    //no idea why one needs to be subtracted from x size
    uint8_t field_definition[7] = {CMD_CHAIN, SET_COLUMN_START_END, start_x, start_x+size_x-1,
                                    SET_PAGE_START_END, start_y, start_y+size_y};
    i2c_send_chunk(DSPL_ADDR, sizeof(field_definition), field_definition);
  
    uint16_t length = (size_x * size_y) + 1;
    uint8_t buffer[length];
    buffer[0] = DATA_CHAIN;

    //single page bitmaps working, now to implement handling bigger bitmaps
    uint16_t i;
    for(i = 0; i<size_x; i++){          //first line of data
        buffer[i+1] = (*(data + i))<<offset;
    }
    for(i = 0; i<data_length; i++){     
        if(i >= data_length-size_x){
            buffer[size_x+i+1] = *(data+i)&offset_mask; 
            buffer[size_x+i+1] = buffer[size_x+i+1]>>(8-offset);
        }
    }
    /*if(data_length == size_x){
        i = 0;
    } else{ 
        i = size_x;
    }
    for(i; i < data_length; i++){
        if(i > data_length-size_x){
            
        buffer[i+1] |= 0x00|(*(data + (i-size_x))|offset_mask);
        send_frame((uint8_t) 'a');
        send_frame(*(data+i-size_x));
        send_frame(buffer[i+1]);
        } else{
            buffer[i+1] = *(data + (i-size_x))|offset_mask;
            buffer[i+1] |= *(data + (i+size_x))|~offset_mask;
            send_frame((uint8_t) 'b');
            send_frame(*(data+i-size_x));
            send_frame(buffer[i+1]);
        }
    }*/

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