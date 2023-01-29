/*
 ============================================================================
 Name        : EX1\3.c
 Author      : Misho
 Description : Write C Program to find the largest number among three numbers
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	float x,y,z;
	printf("Enter three numbers : ");
	fflush(stdout);
	scanf("%f %f %f",&x,&y,&z);
	if(x>=y)
	{
		if(x>=z)
			printf("Largest Numer = %f",x);
		else
			printf("Largest Numer = %f",z);
	}
	else
	{
		if(y>=z)
			printf("Largest Numer = %f",y);
		else
			printf("Largest Numer = %f",z);
	}
	return 0;
}
