#include<avr/io.h>
#include<util/delay.h>

#include"i2c.h"
#include"SSD1306.h"

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

    i2c_init();
    SSD1306_init(32);
    blink();

    clear_display();
    char string[] = "!~ASDFGHJK";
    char string2[] = "opqrstuvwxyz~";
    print(string, sizeof(string), 0, 0);
    print(string2, sizeof(string2), 0, 16);
    _delay_ms(1000);


    while (1){
        blink();
    }

    return(0);
}