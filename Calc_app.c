#include "LCD.h"
#include "keypad.h"

int main(void)
{
	LCD_init();
	keypad_init();
	uint8_t key, x, opp, y, flag=0;
	
	
    while(1)
    {
		while(keypad_read() == 'O'); // digit 1
		key = keypad_read();
		LCD_write_char(key);
		if(key >='0' && key <='9'){
			x= key -'0';
		}
		else {
			flag = 1;
		}
		
		while(keypad_read() != 'O'); //button still pressed
		
		//////////////////////////
				
		while(keypad_read() =='O');// Operation button
		key = keypad_read();
		LCD_write_char(key);
		if(key == '+' || key == '-' || key == '/' || key == 'x'){
			opp = key;
		}
		else {
			flag = 1;
		}
				
				
		while(keypad_read() != 'O'); //button still pressed
				
		/////////////////////////////////
		
		while(keypad_read() =='O');//digit 2
		key = keypad_read();
		LCD_write_char(key);
		if(key >='0' && key <='9'){
			y= key -'0';
		}
		else {
			flag = 1;
		}
			
		
		while(keypad_read() != 'O'); //button still pressed
		
		//////////////////////////
		
		while(keypad_read() == 'O');// = button
		key = keypad_read();
		LCD_write_char(key);
		LCD_write_command(0xc0);
		if(flag == 1){
			LCD_write_string("WRONG ENTRY ");
			flag= 0;
		}
		else if(key == '='){
			switch(opp){
				case '+': LCD_write_num(x+y); break;
				case '-': LCD_write_num(x-y); break;
				case '/': if(y != 0) LCD_write_num(x/y); else LCD_write_string("wrong entry"); break;
				case 'x': LCD_write_num(x*y); break;
				
			}
		}
		else{
			LCD_write_string("WRONG ENTRY");
		}
		
		while(keypad_read() != 'O'); //button still pressed
		
		//////////////////////////////
		
		while (keypad_read() != 'C'); // clear LCD
		if(keypad_read() == 'C'){
			LCD_write_command(1); // clear and start in first position
		}
		

		while (keypad_read() == 'O');
		
		
			
		     
    }
}