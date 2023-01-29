/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Description : Write C Program to check if a character is an alphabet or not
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	char x;
	printf("Enter a Character : ");
	fflush(stdout);
	scanf("%c",&x);
	if(64<x&&x<128)
		printf("%c is an alphabet",x);
	else
		printf("%c is not an alphabet",x);
	return 0;
}
