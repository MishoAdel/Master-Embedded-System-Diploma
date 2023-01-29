/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Description : Write Source Code to Swap Two Numbers
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

int main(void){
	float a,b,tmp;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	tmp=a;
	a=b;
	b=tmp;
	printf("After swapping, value of a = %f\r\nAfter swapping, value of b = %f",a,b);
	return 0;
}
