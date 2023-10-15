/*
 * keypad.c
 *
 * Created: 8/19/2023 10:57:09 AM
 *  Author: Khater
 */ 

#include "keypad.h"
#include "keypad_cfg.h"

uint8_t keypad_matrix[] = {
	'7', '8', '9', '/',
	'4', '5', '6', 'x',
	'1', '2', '3', '-',
	'C', '0', '=', '+',
};
void keypad_init(void){
	KEYPAD_PORT_INIT();
}


uint8_t keypad_read(void){
	uint8_t i = 0;		
	for(i = 0; i < 4; i++){
		switch(i){
			case 0: KEYPAD_A(0);	KEYPAD_B(1);	KEYPAD_C(1);	KEYPAD_D(1); break;
			case 1: KEYPAD_A(1);	KEYPAD_B(0);	KEYPAD_C(1);	KEYPAD_D(1); break;
			case 2: KEYPAD_A(1);	KEYPAD_B(1);	KEYPAD_C(0);	KEYPAD_D(1); break;
			case 3: KEYPAD_A(1);	KEYPAD_B(1);	KEYPAD_C(1);	KEYPAD_D(0); break;
		}
		
		if(KEYPAD_1 == 0) {return keypad_matrix[4 * i + 0];}
		if(KEYPAD_2 == 0) {return keypad_matrix[4 * i + 1];}
		if(KEYPAD_3 == 0) {return keypad_matrix[4 * i + 2];}
		if(KEYPAD_4 == 0) {return keypad_matrix[4 * i + 3];}
		_delay_ms(10);
	}		
	return 'O';		
}