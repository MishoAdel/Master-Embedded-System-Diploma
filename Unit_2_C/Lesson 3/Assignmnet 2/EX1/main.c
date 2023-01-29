/*
 ============================================================================
 Name        : EX1.c
 Author      : Misho
 Description : Write C Program to check whether a number is even or odd
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int x;
	printf("Enter an integer you want to check : ");
	fflush(stdout);
	scanf("%d",&x);
	if (x%2==0)
		printf("%d is even",x);
	else
		printf("%d is odd",x);
	return 0;
}
