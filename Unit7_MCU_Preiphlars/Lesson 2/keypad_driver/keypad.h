/*
 * keypad.h
 *
 * Created: 9/6/2023 6:05:09 PM
 *  Author:  Michel Adel
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL

#include <avr/io.h>
#include "util/delay.h"


#define R0_PIN 0
#define R1_PIN 1
#define R2_PIN 2
#define R3_PIN 3
#define C0_PIN 4
#define C1_PIN 5
#define C2_PIN 6
#define C3_PIN 7

#define KEYPAD_PORT PORTC
#define KEPAD_DIRECTION DDRC
#define KEYPAD_PIN PINC

void Keypad_init();
char keypad_getchar();


#endif /* KEYPAD_H_ */