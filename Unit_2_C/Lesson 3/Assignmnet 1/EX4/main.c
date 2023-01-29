/*
 ============================================================================
 Name        : EX4.c
 Author      : Misho
 Description : Write C Program to Multiply two Floating Point Numbers
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float x, y;
	printf("Enter two numbers: ");
	fflush(stdout);
	scanf("%f %f",&x , &y);
	printf("Product = %f",x*y);
	return 0;
}

