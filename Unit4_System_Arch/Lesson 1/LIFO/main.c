/*
 * main.c
 *[
 *  Created on: Jul 23, 2023
 *      Author: mesho
 */
#include "stdio.h"
#include "LIFO.h"



int main(){
	//DataType arr[10]={0}; // To try static memory uncomment this line an replace second argument in init with "arr"
	DataType poped;
	LIFO_Stack buff1;
	LIFO_init(&buff1, (DataType*) malloc(10),10);//Using Dynamic Memory
	if(LIFO_display_all(&buff1)==LIFO_EMPTY) //check for displaying empty stack
		Pprintf("Empty Stack\n");

	if (LIFO_pop(&buff1,&poped)==LIFO_EMPTY) //check for pop empty stack
		Pprintf("Empty Stack Can.t pop\n");
	LIFO_push(&buff1,3);
	LIFO_push(&buff1,7);
	LIFO_push(&buff1,2);
	LIFO_push(&buff1,0);
	LIFO_push(&buff1,5);
	printf("=======================================\n");
	if((LIFO_display_all(&buff1))==LIFO_EMPTY) //checking pushing order
			Pprintf("Empty Stack");
	printf("=======================================\n");
	LIFO_pop(&buff1,&poped); //checking popping order
	Pprintf("%d \n",poped);
	LIFO_pop(&buff1,&poped);
	Pprintf("%d \n",poped);
	printf("=======================================\n");
	if(LIFO_display_all(&buff1)==LIFO_EMPTY) //rechecking stack after pop
			Pprintf("Empty Stack\n");
	printf("=======================================\n");
	LIFO_push(&buff1,22);
	LIFO_push(&buff1,11);
	LIFO_push(&buff1,13);
	if(LIFO_display_all(&buff1)==LIFO_EMPTY)
			Pprintf("Empty Stack\n");
	printf("=======================================\n");
	if(LIFO_display(&buff1,2)==LIFO_NOT_ENOUGH_ITEMS) //checking display function
			Pprintf("No enough items\n");
	printf("=======================================\n");
	if(LIFO_display(&buff1,5)==LIFO_NOT_ENOUGH_ITEMS)
			Pprintf("No enough items\n");
	printf("=======================================\n");
	if(LIFO_display(&buff1,10)==LIFO_NOT_ENOUGH_ITEMS)
			Pprintf("No enough items\n");
	printf("=======================================\n");
	LIFO_reset(&buff1);
	if(LIFO_display_all(&buff1)==LIFO_EMPTY) //checking reset function
			Pprintf("Empty Stack\n");
	printf("=======================================\n");
	int i=0;
	for(i=0;i<10;i++)
		LIFO_push(&buff1,i);
	if(LIFO_push(&buff1,10)== LIFO_FULL) //checking push to full stack
		Pprintf("Full Stack");
	return 0;
}
