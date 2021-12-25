#include<avr/io.h>
#include<avr/pgmspace.h>

#define FONT_BITMAPS_1 verdana_7ptBitmaps_1
#define FONT_DESCRIPTORS_1 verdana_7ptDescriptors_1
#define FONT_BITMAPS_2 verdana_7ptBitmaps_2
#define FONT_DESCRIPTORS_2 verdana_7ptDescriptors_2

const uint8_t verdana_7ptBitmaps_1[253] PROGMEM;
const uint8_t verdana_7ptBitmaps_2[164] PROGMEM;
const uint16_t verdana_7ptDescriptors_1[54][4] PROGMEM;
const uint16_t verdana_7ptDescriptors_2[41][4] PROGMEM;
// const uint16_t verdana_7ptDescriptors[95][4] PROGMEM;
// const uint8_t verdana_7ptBitmaps[417] PROGMEM;