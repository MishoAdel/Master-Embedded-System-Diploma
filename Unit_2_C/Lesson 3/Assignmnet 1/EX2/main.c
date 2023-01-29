/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho
 Description : Write C Program to Print a Integer Entered by a User
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x;
	printf("Enter an Integer : ");
	fflush(stdout);
	scanf("%d",&x);
	printf("You entered : %d",x);
	return 0;
}
