#include<avr/io.h>
#include<util/delay.h>
#include"i2c.h"
#include"SSD1306.h"
#include"uart.h"

#define LED PB5

void blink(void){
    DDRB |= (1 << LED);

    PORTB |= (1 << LED);
    _delay_ms(125);
    PORTB &= ~(1 << LED);
    _delay_ms(125);
    PORTB |= (1 << LED);
    _delay_ms(125);
    PORTB &= ~(1 << LED);
}

int main(void){
    blink();
    i2c_init();
    SSD1306_init(32);
    uart_init(9600);
    
    clear_display();

    blink();

    uint8_t bitmap[10] = {0xAA, 0xAA, 0xAA, 0x55, 0x55, 0x55, 0xFF, 0xFF, 0xFF, 0xFF};
    write_field(60, 13, 10, 8, bitmap, sizeof(bitmap));
    //uint8_t dupa = 0xFF;
    //write_field(20, 5, 1, 8, &dupa, 1);

    write_field(0, 0, 10, 8, bitmap, 4);

    while (1){
        blink();
    }

    return(0);
}