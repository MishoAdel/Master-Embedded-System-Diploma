/*
 ============================================================================
 Name        : Q7.c
 Author      : Misho
 Description : write c function to sum numbers from 1 to 100(without loop)?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum(int num);

int main(void) {
	int num;
	printf("Enter a positive integer: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Sum of %d = %d",num,sum(num));
	return 0;
}

int sum(int num){
	if (num==0)
		return 0;
	return num + sum(num-1);
}
