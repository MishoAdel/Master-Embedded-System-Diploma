/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Description : Write Source Code to Swap Two Numbers without temp variable.
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

int main(void){
	float a,b;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	a+=b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %f\r\nAfter swapping, value of b = %f",a,b);
	return 0;
}
