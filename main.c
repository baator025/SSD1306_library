#include<avr/io.h>
#include<util/delay.h>

#include"i2c.h"
#include"SSD1306.h"
#include"uart.h"
#include"bitmaps.h"

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
    uint8_t i;
    for (i = 0; i < 4; i++){
        write_field(2+(i*6), 5+offsets_vertical[i], 5, 8, test_writing[i], 5);
    }
    for (i = 0; i < 4; i++){
        write_field(30+(i*6), 5+offsets_vertical[i], 5, 8, test_writing[i], 5);
    }
    for (i = 0; i < 4; i++){
        write_field(2+(i*6), 17+offsets_vertical[i], 5, 8, test_writing[i], 5);
    }
    for (i = 0; i < 4; i++){
        write_field(30+(i*6), 17+offsets_vertical[i], 5, 8, test_writing[i], 5);
    }
    for (i = 0; i < 4; i++){
        write_field(90+(i*6), 21+offsets_vertical[i], 5, 8, test_writing[i], 5);
    }

    _delay_ms(2000);

    clear_display();
    write_field(0, 0, 128, 32, cat, sizeof(cat));

    _delay_ms(2000);

    clear_display();
    write_field(0, 0, 4, 16, bitmap, sizeof(bitmap));

    _delay_ms(2000);

    clear_display();
    write_field(0, 0, 128, 32, Dachshund, sizeof(Dachshund));


    while (1){
        blink();
    }

    return(0);
}