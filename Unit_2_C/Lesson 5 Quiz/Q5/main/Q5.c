/*
 ============================================================================
 Name        : Q5.c
 Author      : Misho
 Description : Write a C function to clear a specific bit on a number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int restbit(int num,int bit);

int main(void) {
	int num,bit;
	printf("Enter number = ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Enter position = ");
	fflush(stdout);
	scanf("%d",&bit);
	printf("%d", restbit(num,bit));
	return 0;
}

int restbit(int num,int bit)
{
	num&=~(1<<bit);
	return num;
}
