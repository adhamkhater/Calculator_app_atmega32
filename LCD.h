/*
 * LCD.h
 *
 * Created: 8/18/2023 10:49:48 AM
 *  Author: Khater
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "generic_macros_header.h"
#define SECOND_LINE(x) (0xc0 + x)
#define FIRST_LINE(x) (0x80 + x)

void LCD_init(void);
void LCD_write_command(uint8_t);
void LCD_write_char(uint8_t);
void LCD_write_string(uint8_t *);
void LCD_write_num(uint16_t);


#endif /* LCD_H_ */