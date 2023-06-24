/*
 ============================================================================
 Name        : EX3.c
 Author      : Misho
 Description : Write a program in C to print a string in reverse using a pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char arr[100];
	printf("Enter a String: ");
	fflush(stdout);
	gets(arr);
	int size;
	for(size=0;arr[size]!='\0';size++);
	char *ptr;
	ptr=&arr[size-1];
	printf("Reverse of the string is : ");
	for(;size>0;ptr--,size--)
		printf("%c",*ptr);
	return 0;
}
