/*
 ============================================================================
 Name        : Q2.c
 Author      : Misho
 Description : write c function to take an integer number and calculate it's square root?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

double root(int num);

int main(void) {
	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Root=> %lf",root(num));
	return 0;
}

double root(int num){

	return pow(num,0.5);
}
