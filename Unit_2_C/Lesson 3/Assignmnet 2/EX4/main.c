/*
 ============================================================================
 Name        : EX4.c
 Author      : Misho
 Description : Write C Program to check if a number is positive or negative
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	float x;
	printf("Enter a number : ");
	fflush(stdout);
	scanf("%f",&x);
	if(x>0)
		printf("%f is Positive",x);
	else if (x<0)
		printf("%f is Negative",x);
	else
		printf("You Entered Zero");
	return 0;
}
