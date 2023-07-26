/*
 * LIFO.h
 * Author: Michel Adel
 */

#ifndef LIFO_H_
#define LIFO_H_

#define Pprintf(...)	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);}

#include "stdio.h"
#include "stdint.h"
// Define Data Type
#define DataType uint32_t
// LIFO components
typedef struct {
	int length;
	int count;
	DataType* base;
	DataType* head;
}LIFO_Stack;
//LIFO error
typedef enum {
	LIFO_NO_ERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NOT_ENOUGH_ITEMS
}E_LIFO_RETURN;

//User Functions
E_LIFO_RETURN LIFO_init(LIFO_Stack* My_LIFO,DataType* P_Stack,int length);		//initialize the LIFO
E_LIFO_RETURN LIFO_push(LIFO_Stack* My_LIFO,DataType item);						//adds one items to LIFo
E_LIFO_RETURN LIFO_pop(LIFO_Stack* My_LIFO,DataType *store_P);					//pop one item from Stack and stores it in address store_P
E_LIFO_RETURN LIFO_empty(LIFO_Stack* My_LIFO);									//Checks if Stack is empty
E_LIFO_RETURN LIFO_full(LIFO_Stack* My_LIFO);									//Check if Stack is full
E_LIFO_RETURN LIFO_reset(LIFO_Stack* My_LIFO);									//resets the LIFO
E_LIFO_RETURN LIFO_display(LIFO_Stack* My_LIFO,int num);						//Display next to be out n items
E_LIFO_RETURN LIFO_display_all(LIFO_Stack* My_LIFO);							//Display all items

#endif /* LIFO_H_ */
