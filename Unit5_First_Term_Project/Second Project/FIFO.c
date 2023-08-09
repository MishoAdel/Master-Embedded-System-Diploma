/*
 * FIFO.c
 *
 *  Created on: Jul 24, 2023
 *      Author: mesho
 */


#include "FIFO.h"

E_FIFO_RETURN FIFO_full(FIFO_Queue* My_Queue){
	if(My_Queue->count==My_Queue->length)
		return FIFO_FULL;
	else
		return FIFO_NO_ERROR;
}

E_FIFO_RETURN FIFO_empty(FIFO_Queue* My_Queue){
	if(My_Queue->tail==My_Queue->head)
		return FIFO_EMPTY;
	else
		return FIFO_NO_ERROR;
}

E_FIFO_RETURN FIFO_init(FIFO_Queue* My_Queue,DataType* P_Queue,int length){
	My_Queue->count=0;
	My_Queue->base=P_Queue;
	My_Queue->head=P_Queue;
	My_Queue->tail=P_Queue;
	My_Queue->length=length;
	return FIFO_NO_ERROR;
}

E_FIFO_RETURN FIFO_enqueue(FIFO_Queue* My_Queue,DataType *item){
	if(FIFO_full(My_Queue)==FIFO_FULL)
		return FIFO_FULL;
	else
		*(My_Queue->head)=*(item);
	if(My_Queue->head == (My_Queue->base + (My_Queue->length)*sizeof(DataType) ) )
		My_Queue->head=My_Queue->base;
	else
		My_Queue->head++;
	My_Queue->count++;
	return FIFO_NO_ERROR;
}

E_FIFO_RETURN FIFO_dequeue(FIFO_Queue* My_Queue,DataType *store_P){
	if(FIFO_empty(My_Queue)==FIFO_EMPTY)
		return FIFO_EMPTY;
	*(store_P)=*(My_Queue->tail);
	if(My_Queue->tail == (My_Queue->base + (My_Queue->length)*sizeof(DataType) ) )
		My_Queue->tail=My_Queue->base;
	else
		My_Queue->tail++;
	My_Queue->count--;
	return FIFO_NO_ERROR;
}


E_FIFO_RETURN FIFO_reset(FIFO_Queue* My_Queue){
	My_Queue->head=My_Queue->base;
	My_Queue->tail=My_Queue->base;
	My_Queue->count=0;
	return FIFO_EMPTY;
}

E_FIFO_RETURN FIFO_display(FIFO_Queue* My_Queue,int num){
	if(FIFO_empty(My_Queue)==FIFO_EMPTY)
		return FIFO_EMPTY;
	DataType* temp_P=My_Queue->tail;
	while(num>0){
		//Pprintf("%d \n",*(temp_P));
		display_student(temp_P);
		temp_P++;
		num--;
		if(temp_P == (My_Queue->base + (My_Queue->length)*sizeof(DataType) ) )
			temp_P=My_Queue->base;
		if(temp_P==My_Queue->head)
			return FIFO_NOT_ENOUGH_ITEMS;
	}
	return FIFO_NO_ERROR;
}

E_FIFO_RETURN FIFO_display_all(FIFO_Queue* My_Queue){
	if(FIFO_empty(My_Queue)==FIFO_EMPTY)
		return FIFO_EMPTY;
	DataType* temp_P=My_Queue->tail;
	do{
		display_student(temp_P);
		temp_P++;
		if(temp_P == (My_Queue->base + (My_Queue->length)*sizeof(DataType) ) )
			temp_P=My_Queue->base;
	}while(temp_P!=My_Queue->head);
	return FIFO_NO_ERROR;
}
