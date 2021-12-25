#include"Verdana_7.h"

/* Character bitmaps for Verdana 7pt */
const uint8_t verdana_7ptBitmaps_1[253] PROGMEM = {
	/* @0 ' ' (2 pixels wide) */
	//   
	//   
	//   
	//   
	//   
	//   
	//   
	//   
	//   
	//   
	//   
	//   
	0x00, 0x00, 

	/* @4 '!' (1 pixels wide) */
	// O
	// O
	// O
	// O
	// O
	//  
	// O
	0x5F, 

	/* @5 '"' (3 pixels wide) */
	// O O
	// O O
	// O O
	0x07, 0x00, 0x07, 

	/* @8 '#' (5 pixels wide) */
	//  O O 
	// OOOOO
	//  O O 
	// OOOOO
	//  O O 
	0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 

	/* @13 '$' (5 pixels wide) */
	//   O  
	//   O  
	//  OOOO
	// O O  
	//  OO  
	//   OO 
	//   O O
	// OOOO 
	//   O  
	//   O  
	0x44, 0x4A, 0xFF, 0x52, 0x22,

	/* @23 '%' (9 pixels wide) */
	//  OO   O  
	// O  O O   
	// O  O O   
	//  OO O OO 
	//    O O  O
	//    O O  O
	//   O   OO 
	0x06, 0x09, 0x49, 0x36, 0x08, 0x36, 0x49, 0x48, 0x30, 

	/* @32 '&' (6 pixels wide) */
	//  OO   
	// O  O  
	// O  O  
	//  OO  O
	// O  O O
	// O   O 
	//  OOO O
	0x36, 0x49, 0x49, 0x56, 0x20, 0x58, 

	/* @38 ''' (1 pixels wide) */
	// O
	// O
	// O
	0x07, 

	/* @39 '(' (3 pixels wide) */
	//   O
	//  O 
	// O  
	// O  
	// O  
	// O  
	//  O 
	//   O
	0x3C, 0x42, 0x81, 

	/* @45 ')' (3 pixels wide) */
	// O  
	//  O 
	//   O
	//   O
	//   O
	//   O
	//   O
	//   O
	//  O 
	// O  
	0x81, 0x42, 0x3c,

	/* @51 '*' (5 pixels wide) */
	//   O  
	// O O O
	//  OOO 
	// O O O
	//   O  
	0x0A, 0x04, 0x1F, 0x04, 0x0A, 

	/* @56 '+' (5 pixels wide) */
	//   O  
	//   O  
	// OOOOO
	//   O  
	//   O  
	0x04, 0x04, 0x1F, 0x04, 0x04, 

	/* @61 ',' (2 pixels wide) */
	//  O
	//  O
	// O 
	0x04, 0x03, 

	/* @63 '-' (3 pixels wide) */
	// OOO
	0x01, 0x01, 0x01, 

	/* @66 '.' (1 pixels wide) */
	// O
	// O
	0x03, 

	/* @67 '/' (4 pixels wide) */
	//    O
	//    O
	//   O 
	//   O 
	//  O  
	//  O  
	//  O  
	// O   
	// O   
	0x80, 0x70, 0x0C, 0x03, 

	/* @75 '0' (5 pixels wide) */
	//  OOO 
	// O   O
	// O   O
	// O   O
	// O   O
	// O   O
	//  OOO 
	0x3E, 0x41, 0x41, 0x41, 0x3E, 

	/* @80 '1' (3 pixels wide) */
	//  O 
	// OO 
	//  O 
	//  O 
	//  O 
	//  O 
	// OOO
	0x42, 0x7F, 0x40, 

	/* @83 '2' (5 pixels wide) */
	//  OOO 
	// O   O
	//     O
	//    O 
	//   O  
	//  O   
	// OOOOO
	0x42, 0x61, 0x51, 0x49, 0x46, 

	/* @88 '3' (5 pixels wide) */
	//  OOO 
	// O   O
	//     O
	//   OO 
	//     O
	// O   O
	//  OOO 
	0x22, 0x41, 0x49, 0x49, 0x36, 

	/* @93 '4' (5 pixels wide) */
	//    O 
	//   OO 
	//  O O 
	// O  O 
	// OOOOO
	//    O 
	//    O 
	0x18, 0x14, 0x12, 0x7F, 0x10, 

	/* @98 '5' (5 pixels wide) */
	// OOOOO
	// O    
	// OOOO 
	//     O
	//     O
	// O   O
	//  OOO 
	0x27, 0x45, 0x45, 0x45, 0x39, 

	/* @103 '6' (5 pixels wide) */
	//   OO 
	//  O   
	// O    
	// OOOO 
	// O   O
	// O   O
	//  OOO 
	0x3C, 0x4A, 0x49, 0x49, 0x30, 

	/* @108 '7' (5 pixels wide) */
	// OOOOO
	//     O
	//    O 
	//    O 
	//   O  
	//   O  
	//   O  
	0x01, 0x01, 0x71, 0x0D, 0x03, 

	/* @113 '8' (5 pixels wide) */
	//  OOO 
	// O   O
	// O   O
	//  OOO 
	// O   O
	// O   O
	//  OOO 
	0x36, 0x49, 0x49, 0x49, 0x36, 

	/* @118 '9' (5 pixels wide) */
	//  OOO 
	// O   O
	// O   O
	//  OOOO
	//     O
	//    O 
	//  OO  
	0x06, 0x49, 0x49, 0x29, 0x1E, 

	/* @123 ':' (1 pixels wide) */
	// O
	// O
	//  
	// O
	// O
	0x1B, 

	/* @124 ';' (2 pixels wide) */
	//  O
	//  O
	//   
	//  O
	//  O
	// O 
	0x20, 0x1B, 

	/* @126 '<' (5 pixels wide) */
	//     O
	//   OO 
	// OO   
	//   OO 
	//     O
	0x04, 0x04, 0x0A, 0x0A, 0x11, 

	/* @131 '=' (5 pixels wide) */
	// OOOOO
	//      
	// OOOOO
	0x05, 0x05, 0x05, 0x05, 0x05, 

	/* @136 '>' (5 pixels wide) */
	// O    
	//  OO  
	//    OO
	//  OO  
	// O    
	0x11, 0x0A, 0x0A, 0x04, 0x04, 

	/* @141 '?' (4 pixels wide) */
	// OOO 
	//    O
	//    O
	//   O 
	//  O  
	//     
	//  O  
	0x01, 0x51, 0x09, 0x06, 

	/* @145 '@' (8 pixels wide) */
	//   OOOOO 
	//  O     O
	// O  OOO O
	// O O  O O
	// O O  O O
	// O  OO O 
	//  O      
	//   OOOOO 
	0x3C, 0x42, 0x99, 0xA5, 0xA5, 0x9D, 0xA1, 0x1E, 

	/* @153 'A' (6 pixels wide) */
	//   OO  
	//   OO  
	//  O  O 
	//  O  O 
	// OOOOOO
	// O    O
	// O    O
	0x70, 0x1C, 0x13, 0x13, 0x1C, 0x70, 

	/* @159 'B' (5 pixels wide) */
	// OOO  
	// O  O 
	// O  O 
	// OOOO 
	// O   O
	// O   O
	// OOOO 
	0x7F, 0x49, 0x49, 0x4E, 0x30, 

	/* @164 'C' (6 pixels wide) */
	//   OOO 
	//  O   O
	// O     
	// O     
	// O     
	//  O   O
	//   OOO 
	0x1C, 0x22, 0x41, 0x41, 0x41, 0x22, 

	/* @170 'D' (6 pixels wide) */
	// OOOO  
	// O   O 
	// O    O
	// O    O
	// O    O
	// O   O 
	// OOOO  
	0x7F, 0x41, 0x41, 0x41, 0x22, 0x1C, 

	/* @176 'E' (5 pixels wide) */
	// OOOOO
	// O    
	// O    
	// OOOO 
	// O    
	// O    
	// OOOOO
	0x7F, 0x49, 0x49, 0x49, 0x41, 

	/* @181 'F' (5 pixels wide) */
	// OOOOO
	// O    
	// O    
	// OOOO 
	// O    
	// O    
	// O    
	0x7F, 0x09, 0x09, 0x09, 0x01, 

	/* @186 'G' (6 pixels wide) */
	//   OOO 
	//  O   O
	// O     
	// O  OOO
	// O    O
	//  O   O
	//   OOO 
	0x1C, 0x22, 0x41, 0x49, 0x49, 0x3A, 

	/* @192 'H' (6 pixels wide) */
	// O    O
	// O    O
	// O    O
	// OOOOOO
	// O    O
	// O    O
	// O    O
	0x7F, 0x08, 0x08, 0x08, 0x08, 0x7F, 

	/* @198 'I' (3 pixels wide) */
	// OOO
	//  O 
	//  O 
	//  O 
	//  O 
	//  O 
	// OOO
	0x41, 0x7F, 0x41, 

	/* @201 'J' (4 pixels wide) */
	//   OO
	//    O
	//    O
	//    O
	//    O
	//    O
	// OOO 
	0x40, 0x40, 0x41, 0x3F, 

	/* @205 'K' (5 pixels wide) */
	// O   O
	// O  O 
	// O O  
	// OO   
	// O O  
	// O  O 
	// O   O
	0x7F, 0x08, 0x14, 0x22, 0x41, 

	/* @210 'L' (5 pixels wide) */
	// O    
	// O    
	// O    
	// O    
	// O    
	// O    
	// OOOOO
	0x7F, 0x40, 0x40, 0x40, 0x40, 

	/* @215 'M' (7 pixels wide) */
	// OO   OO
	// OO   OO
	// O O O O
	// O O O O
	// O  O  O
	// O  O  O
	// O     O
	0x7F, 0x03, 0x0C, 0x30, 0x0C, 0x03, 0x7F, 

	/* @222 'N' (6 pixels wide) */
	// O    O
	// OO   O
	// O O  O
	// O  O O
	// O   OO
	// O    O
	// O    O
	0x7F, 0x02, 0x04, 0x08, 0x10, 0x7F, 

	/* @228 'O' (7 pixels wide) */
	//   OOO  
	//  O   O 
	// O     O
	// O     O
	// O     O
	//  O   O 
	//   OOO  
	0x1C, 0x22, 0x41, 0x41, 0x41, 0x22, 0x1C, 

	/* @235 'P' (5 pixels wide) */
	// OOOO 
	// O   O
	// O   O
	// O   O
	// OOOO 
	// O    
	// O    
	0x7F, 0x11, 0x11, 0x11, 0x0E, 

	/* @240 'Q' (7 pixels wide) */
	//   OOO  
	//  O   O 
	// O     O
	// O     O
	// O     O
	//  O   O 
	//   OOO  
	//     O 
	//      OO
	0x1C, 0x22, 0x41, 0x51, 0x61, 0x62, 0x9C,
	// 0x0C, 0x12, 0x21, 0x21, 0x52, 0x8C, 0x80,

	/* @254 'R' (5 pixels wide) */
	// OOOO 
	// O   O
	// O   O
	// OOOO 
	// O O  
	// O  O 
	// O   O
	0x7F, 0x09, 0x19, 0x29, 0x46, 

	/* @259 'S' (5 pixels wide) */
	//  OOO 
	// O   O
	// O    
	//  OOO 
	//     O
	// O   O
	//  OOO 
	0x26, 0x49, 0x49, 0x49, 0x32, 

	/* @264 'T' (7 pixels wide) */
	// OOOOOOO
	//    O   
	//    O   
	//    O   
	//    O   
	//    O   
	//    O   
	0x01, 0x01, 0x01, 0x7F, 0x01, 0x01, 0x01, 

	/* @271 'U' (6 pixels wide) */
	// O    O
	// O    O
	// O    O
	// O    O
	// O    O
	// O    O
	//  OOOO 
	0x3F, 0x40, 0x40, 0x40, 0x40, 0x3F, 
};

const uint8_t verdana_7ptBitmaps_2[164] PROGMEM = {

	/* @277 'V' (6 pixels wide) */
	// O    O
	// O    O
	// O    O
	//  O  O 
	//  O  O 
	//   OO  
	//   OO  
	0x07, 0x18, 0x60, 0x60, 0x18, 0x07, 

	/* @283 'W' (7 pixels wide) */
	// O     O
	// O  O  O
	// O  O  O
	// O O O O
	// O O O O
	//  O   O 
	//  O   O 
	0x1F, 0x60, 0x18, 0x06, 0x18, 0x60, 0x1F, 

	/* @290 'X' (5 pixels wide) */
	// O   O
	// O   O
	//  O O 
	//   O  
	//  O O 
	// O   O
	// O   O
	0x63, 0x14, 0x08, 0x14, 0x63, 

	/* @295 'Y' (5 pixels wide) */
	// O   O
	// O   O
	//  O O 
	//  O O 
	//   O  
	//   O  
	//   O  
	0x03, 0x0C, 0x70, 0x0C, 0x03, 

	/* @300 'Z' (5 pixels wide) */
	// OOOOO
	//     O
	//    O 
	//   O  
	//  O   
	// O    
	// OOOOO
	0x61, 0x51, 0x49, 0x45, 0x43, 

	/* @305 '[' (2 pixels wide) */
	// OO
	// O 
	// O 
	// O 
	// O 
	// O 
	// O 
	// O 
	// O 
	// OO
	0xFF, 0x81, 

	/* @309 '\' (4 pixels wide) */
	// O   
	// O   
	//  O  
	//  O  
	//  O  
	//   O 
	//   O 
	//    O
	//    O
	0x03, 0x1C, 0x60, 0x80,

	/* @317 ']' (2 pixels wide) */
	// OO
	//  O
	//  O
	//  O
	//  O
	//  O
	//  O
	//  O
	//  O
	// OO
	0x81, 0xFF, 

	/* @321 '^' (5 pixels wide) */
	//   O  
	//  O O 
	// O   O
	0x04, 0x02, 0x01, 0x02, 0x04, 

	/* @326 '_' (6 pixels wide) */
	// OOOOOO
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 

	/* @332 '`' (2 pixels wide) */
	// O 
	//  O
	0x01, 0x02, 

	/* @334 'a' (4 pixels wide) */
	//  OO 
	//    O
	//  OOO
	// O  O
	//  OOO
	0x08, 0x15, 0x15, 0x1E, 

	/* @338 'b' (4 pixels wide) */
	// O   
	// O   
	// O   
	// OOO 
	// O  O
	// O  O
	// O  O
	// OOO 
	0xFF, 0x88, 0x88, 0x70, 

	/* @342 'c' (4 pixels wide) */
	//  OOO
	// O   
	// O   
	// O   
	//  OOO
	0x0E, 0x11, 0x11, 0x11, 

	/* @346 'd' (4 pixels wide) */
	//    O
	//    O
	//    O
	//  OOO
	// O  O
	// O  O
	// O  O
	//  OOO
	0x70, 0x88, 0x88, 0xFF, 

	/* @350 'e' (4 pixels wide) */
	//  OO 
	// O  O
	// OOOO
	// O   
	//  OOO
	0x0E, 0x15, 0x15, 0x16, 

	/* @354 'f' (4 pixels wide) */
	//   OO
	//  O  
	//  O  
	// OOO 
	//  O  
	//  O  
	//  O  
	//  O  
	0x08, 0xFE, 0x09, 0x01, 

	/* @358 'g' (4 pixels wide) */
	//  OOO
	// O  O
	// O  O
	// O  O
	//  OOO
	//    O
	//  OO 
	0x0E, 0x51, 0x51, 0x3F, 

	/* @362 'h' (4 pixels wide) */
	// O   
	// O   
	// O   
	// OOO 
	// O  O
	// O  O
	// O  O
	// O  O
	0xFF, 0x08, 0x08, 0xF0, 

	/* @366 'i' (1 pixels wide) */
	// O
	//  
	// O
	// O
	// O
	// O
	// O
	0x7D, 

	/* @367 'j' (3 pixels wide) */
	//   O
	//    
	//  OO
	//   O
	//   O
	//   O
	//   O
	//   O
	// OO 
	0x80, 0x84, 0x7D,

	/* @373 'k' (4 pixels wide) */
	// O   
	// O   
	// O   
	// O  O
	// O O 
	// OO  
	// O O 
	// O  O
	0xFF, 0x20, 0x50, 0x88, 

	/* @377 'l' (1 pixels wide) */
	// O
	// O
	// O
	// O
	// O
	// O
	// O
	// O
	0xFF, 

	/* @378 'm' (7 pixels wide) */
	// OOO OO 
	// O  O  O
	// O  O  O
	// O  O  O
	// O  O  O
	0x1F, 0x01, 0x01, 0x1E, 0x01, 0x01, 0x1E, 

	/* @385 'n' (4 pixels wide) */
	// OOO 
	// O  O
	// O  O
	// O  O
	// O  O
	0x1F, 0x01, 0x01, 0x1E, 

	/* @389 'o' (4 pixels wide) */
	//  OO 
	// O  O
	// O  O
	// O  O
	//  OO 
	0x0E, 0x11, 0x11, 0x0E, 

	/* @393 'p' (4 pixels wide) */
	// OOO 
	// O  O
	// O  O
	// O  O
	// OOO 
	// O   
	// O   
	0x7F, 0x11, 0x11, 0x0E, 

	/* @397 'q' (4 pixels wide) */
	//  OOO
	// O  O
	// O  O
	// O  O
	//  OOO
	//    O
	//    O
	0x0E, 0x11, 0x11, 0x7F, 

	/* @401 'r' (3 pixels wide) */
	// O O
	// OO 
	// O  
	// O  
	// O  
	0x1F, 0x02, 0x01, 

	/* @404 's' (4 pixels wide) */
	//  OOO
	// O   
	//  OO 
	//    O
	// OOO 
	0x12, 0x15, 0x15, 0x09, 

	/* @408 't' (4 pixels wide) */
	//  O  
	// OOOO
	//  O  
	//  O  
	//  O  
	//   OO
	0x02, 0x1F, 0x22, 0x22, 

	/* @412 'u' (4 pixels wide) */
	// O  O
	// O  O
	// O  O
	// O  O
	//  OOO
	0x0F, 0x10, 0x10, 0x1F, 

	/* @416 'v' (4 pixels wide) */
	// O  O
	// O  O
	// O  O
	//  OO 
	//  OO 
	0x07, 0x18, 0x18, 0x07, 

	/* @420 'w' (5 pixels wide) */
	// O   O
	// O O O
	// O O O
	//  O O 
	//  O O 
	0x07, 0x18, 0x06, 0x18, 0x07, 

	/* @425 'x' (4 pixels wide) */
	// O  O
	// O  O
	//  OO 
	// O  O
	// O  O
	0x1B, 0x04, 0x04, 0x1B, 

	/* @429 'y' (4 pixels wide) */
	// O  O
	// O  O
	// O  O
	//  OO 
	//   O 
	//  O  
	//  O  
	0x07, 0x68, 0x18, 0x07, 

	/* @433 'z' (3 pixels wide) */
	// OOO
	//   O
	//  O 
	// O  
	// OOO
	0x19, 0x15, 0x13, 

	/* @436 '{' (5 pixels wide) */
	//    OO
	//   O  
	//   O  
	//   O  
	//   O  
	// OO   
	//   O  
	//   O  
	//   O  
	//    OO
	0x08, 0x08, 0x76, 0x81, 0x81,

	/* @446 '|' (1 pixels wide) */
	// O
	// O
	// O
	// O
	// O
	// O
	// O
	// O
	// O
	// O
	0xFF,

	/* @448 '}' (5 pixels wide) */
	// OO   
	//   O  
	//   O  
	//   O  
	//   O  
	//    OO
	//   O  
	//   O  
	//   O  
	// OO
	0x81, 0x81, 0x76, 0x08, 0x08, 

	/* @458 '~' (5 pixels wide) */
	//  OO O
	// O OO 
	0x02, 0x01, 0x03, 0x02, 0x01, 
};

/* Character descriptors for Verdana 7pt */
/* { [Char width in bits], [Char height in bits], [Offset into verdana_7ptCharBitmaps in bytes], [vertical offset] } */
const uint16_t verdana_7ptDescriptors_1[54][4] PROGMEM = 
{
    {2, 8, 0, 0}, 		/*   */ 
    {1, 7, 2, 1}, 		/* ! */ 
    {3, 3, 3, 0}, 		/* " */ 
    {5, 5, 6, 2}, 		/* # */ 
    {5, 8, 11, 0}, 		/* $ */ 
    {9, 7, 16, 1}, 		/* % */ 
    {6, 7, 25, 1}, 		/* & */ 
    {1, 3, 31, 0}, 		/* ' */ 
    {3, 8, 32, 0}, 		/* ( */ 
    {3, 8, 35, 0}, 		/* ) */ 
    {5, 5, 38, 0}, 		/* * */ 
    {5, 5, 43, 2}, 		/* + */ 
    {2, 3, 48, 5}, 		/* , */ 
    {3, 1, 50, 4}, 		/* - */ 
    {1, 2, 53, 6}, 		/* . */ 
    {4, 8, 54, 0}, 		/* / */ 
    {5, 7, 58, 1}, 		/* 0 */ 
    {3, 7, 63, 1}, 		/* 1 */ 
    {5, 7, 66, 1}, 		/* 2 */ 
    {5, 7, 71, 1}, 		/* 3 */ 
    {5, 7, 76, 1}, 		/* 4 */ 
    {5, 7, 81, 1}, 		/* 5 */ 
    {5, 7, 86, 1}, 		/* 6 */ 
    {5, 7, 91, 1}, 		/* 7 */ 
    {5, 7, 96, 1}, 		/* 8 */ 
    {5, 7, 101, 1}, 		/* 9 */ 
    {1, 5, 106, 3}, 		/* : */ 
    {2, 6, 107, 2}, 		/* ; */ 
    {5, 5, 109, 2}, 		/* < */ 
    {5, 3, 114, 3}, 		/* = */ 
    {5, 5, 119, 2}, 		/* > */ 
    {4, 7, 124, 1}, 		/* ? */ 
    {8, 8, 128, 0}, 		/* @ */ 
    {6, 7, 136, 1}, 		/* A */ 
    {5, 7, 142, 1}, 		/* B */ 
    {6, 7, 147, 1}, 		/* C */ 
    {6, 7, 153, 1}, 		/* D */ 
    {5, 7, 159, 1}, 		/* E */ 
    {5, 7, 164, 1}, 		/* F */ 
    {6, 7, 169, 1}, 		/* G */ 
    {6, 7, 175, 1}, 		/* H */ 
    {3, 7, 181, 1}, 		/* I */ 
    {4, 7, 184, 1}, 		/* J */ 
    {5, 7, 188, 1}, 		/* K */ 
    {5, 7, 193, 1}, 		/* L */ 
    {7, 7, 198, 1}, 		/* M */ 
    {6, 7, 205, 1}, 		/* N */ 
    {7, 7, 211, 1}, 		/* O */ 
    {5, 7, 218, 1}, 		/* P */ 
    {7, 8, 223, 0}, 		/* Q */ 
    {5, 7, 230, 1}, 		/* R */ 
    {5, 7, 235, 1}, 		/* S */ 
    {7, 7, 240, 1}, 		/* T */ 
    {6, 7, 247, 1}, 		/* U */ 
};
const uint16_t verdana_7ptDescriptors_2[41][4] PROGMEM = {
    {6, 7, 0, 1}, 			/* V */ 
    {7, 7, 6, 1}, 			/* W */ 
    {5, 7, 13, 1}, 			/* X */ 
    {5, 7, 18, 1}, 			/* Y */ 
    {5, 7, 23, 1}, 			/* Z */ 
    {2, 8, 28, 0}, 			/* [ */ 
    {4, 8, 30, 0}, 			/* \ */ 
    {2, 8, 34, 0}, 			/* ] */ 
    {5, 3, 36, 0}, 			/* ^ */ 
    {6, 1, 41, 7}, 			/* _ */ 
    {2, 2, 47, 0}, 			/* ` */ 
    {4, 5, 49, 3}, 			/* a */ 
    {4, 8, 53, 0}, 			/* b */ 
    {4, 5, 57, 3}, 			/* c */ 
    {4, 8, 61, 0}, 			/* d */ 
    {4, 5, 65, 3}, 			/* e */ 
    {4, 8, 69, 0}, 			/* f */ 
    {4, 7, 73, 3}, 			/* g */ 
    {4, 8, 77, 0}, 			/* h */ 
    {1, 7, 81, 1}, 			/* i */ 
    {3, 8, 82, 1}, 			/* j */ 
    {4, 8, 85, 0}, 			/* k */ 
    {1, 8, 89, 0}, 			/* l */ 
    {7, 5, 90, 3}, 			/* m */ 
    {4, 5, 97, 3}, 			/* n */ 
    {4, 5, 101, 3}, 		/* o */ 
    {4, 7, 105, 3}, 		/* p */ 
    {4, 7, 109, 3}, 		/* q */ 
    {3, 5, 113, 3}, 		/* r */ 
    {4, 5, 116, 3}, 		/* s */ 
    {4, 6, 120, 2}, 		/* t */ 
    {4, 5, 124, 3}, 		/* u */ 
    {4, 5, 128, 3}, 		/* v */ 
    {5, 5, 132, 3}, 		/* w */ 
    {4, 5, 137, 3}, 		/* x */ 
    {4, 7, 141, 3}, 		/* y */ 
    {3, 5, 145, 3}, 		/* z */ 
    {5, 8, 148, 0}, 		/* { */ 
    {1, 8, 153, 0}, 		/* | */ 
    {5, 8, 154, 0}, 		/* } */ 
    {5, 2, 159, 4}, 		/* ~ */
};
/* Font information for Verdana 7pt */
// const FONT_INFO verdana_7ptFontInfo =
// {
// 	12, /*  Character height */
// 	' ', /*  Start character */
// 	'~', /*  End character */
// 	verdana_7ptDescriptors, /*  Character descriptor array */
// 	verdana_7ptBitmaps, /*  Character bitmap array */
// };

