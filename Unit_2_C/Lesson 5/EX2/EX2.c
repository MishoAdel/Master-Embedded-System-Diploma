/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho

 Description : Write C program to find factorial using recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int fact(int num);

int main(void) {
	int num;
	printf("Enter a positive integer: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Factorial of %d = %d",num,fact(num));
	return 0;
}

int fact(int num){
	if (num==1||num==0)
		return 1;
	return num * fact(num-1);
}
