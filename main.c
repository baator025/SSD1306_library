#include<avr/io.h>
#include<util/delay.h>
#include<avr/pgmspace.h>

#include"i2c.h"
#include"SSD1306.h"
#include<stdio.h>

#define LED PB5

__flash const uint8_t dupa[4] = {2, 1, 3, 7};

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
    char dupa1[5];
    
    uint8_t i;
    for(i=0; i < sizeof(dupa); i++){
        sprintf(&dupa1[i], "%i", dupa[i]);
    }
    // itoa(dupa[0], dupa1, 10);
    print(dupa1, sizeof(dupa1), 0, 8);
    // char string1[] = " !""#$%&'()*+,-./0123456789";
    // char string2[] = ":;<=>?@ABCDEFGHIJKLMN";
    // char string3[] = "PQRSTUVWXYZabcdefghijk";
    // char string4[] = "lmnopqrstuvwxyz{|}~";
    // print(string1, sizeof(string1), 0, 0);
    // print(string2, sizeof(string2), 0, 8);
    // print(string3, sizeof(string3), 0, 16);
    // print(string4, sizeof(string4), 0, 24);
    _delay_ms(1000);

    while (1){
        blink();
    }

    return(0);
}