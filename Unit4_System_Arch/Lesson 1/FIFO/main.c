/*
 * main.c
 *
 *  Created on: Jul 24, 2023
 *      Author: mesho
 */
#include "stdio.h"
#include "FIFO.h"
int main(){
	FIFO_Queue queue1;
	//DataType arr[10]={0}; // To try static memory uncomment this line an replace second argument in init with "arr"
	DataType out;
	FIFO_init(&queue1, (DataType*) malloc(10),10);//With dynamic memory
	if(FIFO_display_all(&queue1)==FIFO_EMPTY) //check for empty queue
		Pprintf("Empty Queue\n");

	if (FIFO_dequeue(&queue1,&out)==FIFO_EMPTY) //check for dequeue empty queue
		Pprintf("Empty Queue Can.t dequeue\n");
	FIFO_enqueue(&queue1,3);
	FIFO_enqueue(&queue1,7);
	FIFO_enqueue(&queue1,2);
	FIFO_enqueue(&queue1,0);
	FIFO_enqueue(&queue1,5);
	printf("=======================================\n");
	if((FIFO_display_all(&queue1))==FIFO_EMPTY) //checking enqueue order
		Pprintf("Empty Queue");
	printf("=======================================\n");
	FIFO_dequeue(&queue1,&out); //checking dequeue order
	Pprintf("%d \n",out);
	FIFO_dequeue(&queue1,&out);
	Pprintf("%d \n",out);
	printf("=======================================\n");
	if(FIFO_display_all(&queue1)==FIFO_EMPTY) //rechecking queue after dequeue
		Pprintf("Empty Queue\n");
	printf("=======================================\n");
	FIFO_enqueue(&queue1,22);
	FIFO_enqueue(&queue1,11);
	FIFO_enqueue(&queue1,13);
	if(FIFO_display_all(&queue1)==FIFO_EMPTY)
		Pprintf("Empty Queue\n");
	printf("=======================================\n");
	if(FIFO_display(&queue1,2)==FIFO_NOT_ENOUGH_ITEMS) //checking display function
		Pprintf("No enough items\n");
	printf("=======================================\n");
	if(FIFO_display(&queue1,5)==FIFO_NOT_ENOUGH_ITEMS)
		Pprintf("No enough items\n");
	printf("=======================================\n");
	if(FIFO_display(&queue1,10)==FIFO_NOT_ENOUGH_ITEMS)
		Pprintf("No enough items\n");
	printf("=======================================\n");
	FIFO_reset(&queue1);
	if(FIFO_display_all(&queue1)==FIFO_EMPTY) //checking reset function
		Pprintf("Empty Queue\n");
	printf("=======================================\n");
	int i=0;
	for(i=0;i<10;i++)
		FIFO_enqueue(&queue1,i);
	if(FIFO_enqueue(&queue1,10)== FIFO_FULL) //checking enqueue to full queue
		Pprintf("Full Queue");
	return 0;
}
