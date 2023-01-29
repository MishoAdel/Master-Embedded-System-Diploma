/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Description : Write C Program to Find ASCII Value of a Character
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>

int main(void){
	char a;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&a);
	printf("ASCII value of %c = %d",a,a);
	return 0;
}

