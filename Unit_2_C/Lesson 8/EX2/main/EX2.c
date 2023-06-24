/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho
 Description : Write C program to print all the alphabets using pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	char *ptr;
	int i;
	for(i=0;i<27;i++){
		*ptr=i + 'A';
		fflush(stdout);
		printf("%c ",*ptr);
		ptr++;
	}
	return 0;
}
