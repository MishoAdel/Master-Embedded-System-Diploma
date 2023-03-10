/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Version     :
 Copyright   : 
 Description : Write c program to  calculate area of a circle passing arguments to macros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define area(rad) rad*rad*3.14
int main(void) {
	float rad;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&rad);
	printf("Area = %f",area(rad));
	return 0;
}
