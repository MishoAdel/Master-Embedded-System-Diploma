/*
 ============================================================================
 Name        : Q9.c
 Author      : Misho
 Description : Write c function to reverse words in string?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void rev(char sen[],int lenght);

int main(void) {
	char sen[100];
	printf("Enter a sentence: ");
	fflush(stdout);
	gets(sen);
	int length=strlen(sen);
	rev(sen,length);
	printf("%s",sen);
	return 0;
}

void rev(char sen[],int length){
	int i,len1;
	char temp[100];
	for(i=0;i<length;i++)//length of fisrt word
	{
		if(sen[i]==' ')
			{
			len1=i+1;
			break;
			}
	}
	for(i=len1;i<length;i++)//copy second word into temp array
	{
		temp[i-len1]=sen[i];
	}
	temp[length-len1]=' ';
	for(i=0;i<len1;i++)//copy first word into temp array
	{
		temp[i+length-len1+1]=sen[i];
	}
	for(i=0;i<length;i++)//copy temp arr to arr
	{
		sen[i]=temp[i];
	}
}
