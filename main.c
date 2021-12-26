#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>

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

    char string1[] = " !""#$%&'()*+,-./0123456789";
    char string2[] = ":;<=>?@ABCDEFGHIJKLMN";
    char string3[] = "PQRSTUVWXYZabcdefghijk";
    char string4[] = "lmnopqrstuvwxyz{|}~";
    print(string1, sizeof(string1), 0, 0);
    print(string2, sizeof(string2), 0, 8);
    print(string3, sizeof(string3), 0, 16);
    print(string4, sizeof(string4), 0, 24);
    _delay_ms(1000);

    clear_display();
    char string11[]= "abcdghijrpq";
    print_big(string11, sizeof(string11), 0, 0);

    _delay_ms(1000);

    clear_display();
    print(string1, sizeof(string1), 0, 24);
    while (1){
        blink();
    }

    


    return(0);
}