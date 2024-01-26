/*
 * keypad.h
 *
 * Created: 9/6/2023 6:05:09 PM
 *  Author:  Michel Adel
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_



#include "stm32f103c6_GPIO_driver.h"
#include "stm32f103xx.h"



#define R0_PIN 		 GPIO_PIN0
#define R1_PIN 		 GPIO_PIN1
#define R2_PIN 	     GPIO_PIN3
#define R3_PIN		 GPIO_PIN4
#define C0_PIN		 GPIO_PIN5
#define C1_PIN		 GPIO_PIN6
#define C2_PIN		 GPIO_PIN7
#define C3_PIN		 GPIO_PIN8

#define KEYPAD_PORT GPIOB
//#define KEPAD_DIRECTION DDRC
//#define KEYPAD_PIN PINC

void Keypad_init();
char keypad_getchar();


#endif /* KEYPAD_H_ */
