Library of basic functions, allowing to print bitmaps and strings to SSD1306 display.
Library was tested on Atmega328p.

1. Dependencies
    Library requires set of I2C functions, which is inluded in this repo. It can be also found in my I2C library.

2. How it works 
    Library does not buffer the display array in RAM. It is possible to print bitmaps starting from any
    pixel of the display so bitmaps need adjustments if it is printed starting from middle of SSD1306's 
    pages.
    Fonts' glyphs are treated as bitmaps, so it is also possible to start printing strings starting from
    any pixel in the screen. 
    Fonts and bitmaps shall be kept in flash memory. To make it possible, there is a version of write_field
    function, which writes data from flash.

3. Using library in different projects
    1. Copy SSD1306 lib (SSD1306.c, SSD1306.h), I2C lib (I2C.c, I2C.h), and fonts folder with contents to
        your project folder.
    2. If needed, change display address in SSD1306.h
    3. For configuration of fonts, refer to the next paragraph.
    4. Make necessary includes in your files.
    5. Use init functions for I2C and SSD1306 in your main file. 

4. Use of different fonts
    Every font is described in two arrays, one with bitmaps, second with bitmaps offsets and glyph 
    dimensions. Arrays are defined and declared in .c and .h files. Fonts were generated with Dot Factory
    and adjusted with my script, which will be uploaded in near future. :)
    To use different fonts, you will have to copy print function and rename it. For each new print function,
    you will have to put new font's arrays names in place of the old one. Those places are marked with comments.
    I suggest placing all of fonts in fonts\ directory.
