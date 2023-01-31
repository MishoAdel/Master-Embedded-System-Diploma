/*
 ============================================================================
 Name        : EX2.3
 Author      : Misho
 Description : Write C Program to reverse string
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	char str[100],rev[100];
	int i;
	printf("Enter a string: ");
	fflush(stdout);
	gets(str);
	int length = strlen(str);
	rev[length]=0;
	for(i=0 ; i<length ; i++){
		rev[length-1-i]=str[i];
	}
	printf("Reverse string is: %s",rev);
}
