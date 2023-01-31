/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho
 Description : Write C Program to find the length of a string
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	char str[100];
	int i;
	printf("Enter a string: ");
	fflush(stdout);
	gets(str);
	for(i=0 ; str[i]!=0 && i<100 ; i++){}
	printf("Length of string: %d",i);
}
