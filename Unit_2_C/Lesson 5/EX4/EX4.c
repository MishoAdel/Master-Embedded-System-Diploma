/*
 ============================================================================
 Name        : EX4.c
 Author      : Misho

 Description : Write C program to find the power of a number using recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int pow(int base,int power);

int main(void) {
	int base,power;
	printf("Enter a base number: ");
	fflush(stdout);
	scanf("%d",&base);
	printf("Enter a power number (positive integer): ");
	fflush(stdout);
	scanf("%d",&power);
	printf("%d^%d =%d",base,power,pow(base,power));
	return 0;
}

int pow(int base,int power){
	if(power==0)
		return 1;
	else
		power--;
	return base * pow(base,power);
}
