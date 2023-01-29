/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho
 Description : Write C Program to check a vowel or consonant
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	char x;
	printf("Enter an alphabet : ");
	fflush(stdout);
	scanf("%c",&x);
	if(64<x&&x<128)
	{
		switch (x){
			case 'i':
			case 'I':
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'u':
			case 'U':
			case 'o':
			case 'O':
				printf("%c is a vowel",x);
				break;
			default:
				printf("%c is an consonant",x);
			}
	}
	else
		printf("Not an alphabet");
}
