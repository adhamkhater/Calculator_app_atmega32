/*
 * keypad.h
 *
 * Created: 8/19/2023 10:57:21 AM
 *  Author: Khater
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "generic_macros_header.h"

void keypad_init(void);
uint8_t keypad_read(void);


#endif /* KEYPAD_H_ */