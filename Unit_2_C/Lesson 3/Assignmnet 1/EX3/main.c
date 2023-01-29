/*
 ============================================================================
 Name        : EX3.c
 Author      : Misho
 Description : Write C Program to Add Two Integers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x, y;
	printf("Enter Two Integers : ");
	fflush(stdout);
	scanf("%d %d",&x , &y);
	printf("Sum = %d",x+y);
	return 0;
}
