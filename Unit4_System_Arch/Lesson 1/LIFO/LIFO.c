/*
 * LIFO.c
 * Author: Michel Adel
 */

#include "LIFO.h"

E_LIFO_RETURN LIFO_init(LIFO_Stack* My_LIFO,DataType* P_Stack,int length){
	My_LIFO->count=0;
	My_LIFO->base=P_Stack;
	My_LIFO->head=P_Stack;
	My_LIFO->length=length;
	return LIFO_NO_ERROR;
}

E_LIFO_RETURN LIFO_push(LIFO_Stack* My_LIFO,DataType item){
	if(LIFO_full(My_LIFO)==LIFO_FULL) //check if full
		return LIFO_FULL;
	else
		*(My_LIFO->head)=item; //pushing
	My_LIFO->count++;
	My_LIFO->head++;
	return LIFO_NO_ERROR;
}

E_LIFO_RETURN LIFO_pop(LIFO_Stack* My_LIFO,DataType *store_P){
	if(LIFO_empty(My_LIFO)==LIFO_EMPTY) //check if empty
		return LIFO_EMPTY;
	My_LIFO->head--;
	*(store_P)=*(My_LIFO->head); //popping
	My_LIFO->count--;
	return LIFO_NO_ERROR;
}

E_LIFO_RETURN LIFO_empty(LIFO_Stack* My_LIFO){
	if(My_LIFO->base==My_LIFO->head)
		return LIFO_EMPTY;
	else
		return LIFO_NO_ERROR;
}

E_LIFO_RETURN LIFO_full(LIFO_Stack* My_LIFO){
	if(My_LIFO->count==My_LIFO->length)
		return LIFO_FULL;
	else
		return LIFO_NO_ERROR;
}

E_LIFO_RETURN LIFO_reset(LIFO_Stack* My_LIFO){
	My_LIFO->head=My_LIFO->base;
	My_LIFO->count=0;
	return LIFO_EMPTY;
}

E_LIFO_RETURN LIFO_display(LIFO_Stack* My_LIFO,int num){
	if(LIFO_empty(My_LIFO)==LIFO_EMPTY) //check if empty
		return LIFO_EMPTY;
	DataType* temp_P=My_LIFO->head;
	while(num>0){
		temp_P--;
		Pprintf("%d \n",*(temp_P));
		num--;
		if(temp_P==My_LIFO->base) //not enough numers case
			return LIFO_NOT_ENOUGH_ITEMS;
	}
	return LIFO_NO_ERROR;
}

E_LIFO_RETURN LIFO_display_all(LIFO_Stack* My_LIFO){
	if(LIFO_empty(My_LIFO)==LIFO_EMPTY)
		return LIFO_EMPTY;
	DataType* temp_P=My_LIFO->head;
	do{
		temp_P--;
		Pprintf("%d\n",*(temp_P));
	}while(temp_P!=My_LIFO->base);
	return LIFO_NO_ERROR;
}
