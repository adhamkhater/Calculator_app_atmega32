/*
 * keypad_cfg.h
 *
 * Created: 8/19/2023 10:57:32 AM
 *  Author: Khater
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

/* PC0-PC3  output connected to A,B,C,D */

#define KEYPAD_PORT_INIT()  DDRC = 0b00001111; \
						  PORTC =0b11111111;

#define KEYPAD_A(x) if(x == 0) CLRBIT(PORTC, PC0); else SETBIT(PORTC, PC0);
#define KEYPAD_B(x) if(x == 0) CLRBIT(PORTC, PC1); else SETBIT(PORTC, PC1);
#define KEYPAD_C(x) if(x == 0) CLRBIT(PORTC, PC2); else SETBIT(PORTC, PC2);
#define KEYPAD_D(x) if(x == 0) CLRBIT(PORTC, PC3); else SETBIT(PORTC, PC3);

#define KEYPAD_1  READBIT(PINC,PC4)
#define KEYPAD_2  READBIT(PINC,PC5)
#define KEYPAD_3  READBIT(PINC,PC6)
#define KEYPAD_4  READBIT(PINC,PC7) 

#endif /* KEYPAD_CFG_H_ */