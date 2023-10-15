/*
 * LCD.c
 *
 * Created: 8/18/2023 10:49:38 AM
 *  Author: Khater
 */ 
#include "LCD.h"
#include "LCD_cfg.h"

/*****************************************************************************
* Function Name: LCD_init
* Purpose      : Init lcd in 4 bit mode, clear lcd and turn off cursor
* Parameters   : void
* Return value : void
*****************************************************************************/
void LCD_init(void){
	LCD_CFG_PINS();
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);
	
	LCD_write_command(0x28);
	LCD_write_command(0x8);
	LCD_write_command(0x1);
	LCD_write_command(0x6);
	LCD_write_command(0xc);
	_delay_ms(20);	
	
}


/*****************************************************************************
* Function Name: LCD_write_command
* Purpose      : send command to lcd
* Parameters   : cmd: command number
* Return value : void
*****************************************************************************/
void LCD_write_command(uint8_t cmd){
	RS(0); 
	D7(READBIT(cmd,7));
	D6(READBIT(cmd,6));
	D5(READBIT(cmd,5));
	D4(READBIT(cmd,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
	D7(READBIT(cmd,3));
	D6(READBIT(cmd,2));
	D5(READBIT(cmd,1));
	D4(READBIT(cmd,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
}

/*****************************************************************************
* Function Name: LCD_write_char
* Purpose      : send one char to lcd
* Parameters   : data: Ascii value of the char
* Return value : void
*****************************************************************************/
void LCD_write_char(uint8_t data){
	RS(1);
	D7(READBIT(data,7));
	D6(READBIT(data,6));
	D5(READBIT(data,5));
	D4(READBIT(data,4));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
	
	D7(READBIT(data,3));
	D6(READBIT(data,2));
	D5(READBIT(data,1));
	D4(READBIT(data,0));
	EN(1); _delay_ms(1); EN(0); _delay_ms(1);
		
}

void LCD_write_string(uint8_t *txt){
	uint8_t i =0;
	for(i = 0; txt[i] != '\0'; i++){
		LCD_write_char(txt[i]);
	}
}
/*
126 %10 = 6 --> 126 / 10 = 12 
12  %10 = 2 --> 12  / 10 = 1
1   %10 = 1 --> 1 /10 = 0 --------------
126
1+48 ==> i = 2
2+48 ==> i = 1
6+48 ==> i = 0
*/
void LCD_write_num(uint16_t num){
	uint8_t NumDigits[5];
	int8_t i = 0; 
	if(num == 0){
		LCD_write_char(num+48);
		return;
	}
	for(i = 0; num != 0; i++){
		NumDigits[i] = num %10 + 48;
		num /= 10;
	}
	i--;
	for( ; i >= 0; i--){
		LCD_write_char(NumDigits[i]);
	}
	
}