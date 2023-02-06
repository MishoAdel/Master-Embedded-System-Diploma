/*
 ============================================================================
 Name        : EX3.c
 Author      : Misho

 Description : Write C program to reverse a string using recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void rev(char sen[],int lenght,int count);

int main(void) {
	char sen[100];
	printf("Enter a sentence: ");
	fflush(stdout);
	gets(sen);
	int length=strlen(sen);
	rev(sen,length,0);
	printf("%s",sen);
	return 0;
}

void rev(char sen[],int length, int count){
	if(length==count)
		return;
	char temp=sen[length];
	sen[length]=sen[count];
	sen[count]=temp;
	rev(sen,length-1,count+1);
}
