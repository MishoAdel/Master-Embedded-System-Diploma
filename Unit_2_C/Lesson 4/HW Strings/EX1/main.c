/*
 ============================================================================
 Name        : EX1.c
 Author      : Misho
 Description : Write C Program to find the frequency of a character in a string
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	char str[100];
	int i,freq;
	char c;
	printf("Enter a string : ");
	fflush(stdout);
	gets(str);
	printf("Enter a character to find frequency : ");
	fflush(stdout);
	scanf("%c",&c);
	for(i=0 ; str[i]!=0 ; i++){
		if(str[i]==c)
			freq++;
	}
	printf("Frequency of %c is %d",c,freq);
}
