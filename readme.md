Library for printing bitmaps and strings on SSD1306 display by I2C. Library supports
platforms that I worked on.

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

3. To add new platform:
    Library is designed for most of changes to be done in SSD1306_platform_config, SSD1306_low_level_api and CMakeLists.txt
    SSD1306.c and SSD1306.h files should not be changed until neccessary (f.eg. situation
    like in third point of following instructions).

    1. Modify CMakeLists file to add dependencies.
    2. Add platform specific includes and defines in SSD1306_platform_config in similar
    manner to existing platforms.
    3. If necessary modify I2C API to fit your microcontroller capabilities.
    4. Bear in mind, that arrays with glyphs are quite large. If necessary, make sure
    that they are allocated in proper part of memory. For example take a look at
    MEMORY_PREFIX for Atmega - it is necessary to tell microcontroller to keep data in
    flash memory.
    5. Prepare implementations for functions declared in API file. Remember to add .c
    file in CMakeLists

4. Using library in different projects
    <!-- 1. Copy SSD1306 lib (SSD1306.c, SSD1306.h), I2C lib (I2C.c, I2C.h), and fonts folder with contents to
        your project folder.
    2. If needed, change display address in SSD1306.h
    3. For configuration of fonts, refer to the next paragraph.
    4. Make necessary includes in your files.
    5. Use init functions for I2C and SSD1306 in your main file.  -->

4. Use of different fonts
    Every font is described in two arrays, one with bitmaps, second with bitmaps offsets and glyph
    dimensions. Arrays are defined and declared in .c and .h files. Fonts were generated with Dot Factory
    and adjusted with my script, which will be uploaded in near future. :)
    To use different fonts, you will have to copy print function and rename it. For each new print function,
    you will have to put new font's arrays names in place of the old one. Those places are marked with comments.
    I suggest placing all of fonts in fonts\ directory.
