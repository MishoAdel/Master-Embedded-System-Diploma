/*
 * FIFO.h
 *
 *  Created on: Jul 24, 2023
 *      Author: mesho
 */

#ifndef FIFO_H_
#define FIFO_H_

#define Pprintf(...)	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);}

#include "stdio.h"
#include "stdint.h"
// Define Data Type
#define DataType uint32_t
// FIFO components
typedef struct {
	int length;
	int count;
	DataType* base;
	DataType* head;
	DataType* tail;
}FIFO_Queue;
//FIFO error
typedef enum {
	FIFO_NO_ERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL,
	FIFO_NOT_ENOUGH_ITEMS
}E_FIFO_RETURN;

//User Functions
E_FIFO_RETURN FIFO_init(FIFO_Queue* My_Queue,DataType* P_Queue,int length);	//initialize the FIFO
E_FIFO_RETURN FIFO_push(FIFO_Queue* My_Queue,DataType item);				//adds one items to FIFO
E_FIFO_RETURN FIFO_pop(FIFO_Queue* My_Queue,DataType *store_P);				//pop one item from queue and stores it in address store_P
E_FIFO_RETURN FIFO_empty(FIFO_Queue* My_Queue);								//Checks if queue is empty
E_FIFO_RETURN FIFO_full(FIFO_Queue* My_Queue);								//Check if queue is full
E_FIFO_RETURN FIFO_reset(FIFO_Queue* My_Queue);								//resets the FIFO
E_FIFO_RETURN FIFO_display(FIFO_Queue* My_Queue,int num);					//Display last n items
E_FIFO_RETURN FIFO_display_all(FIFO_Queue* My_Queue);						//Display all items



#endif /* FIFO_H_ */
