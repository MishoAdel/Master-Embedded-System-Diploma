/*
 ============================================================================
 Name        : Q8.c
 Author      : Misho
 Description : Write a C function to return the last occurence of a number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int uns(char num[]);

int main(void) {
	char num[100];
	printf("Enter the number: ");
	fflush(stdout);
	gets(num);
	for(int i=0;i<100;i++)
		{
			printf("%d  ",num[i]);
		}
	printf("%s ==> %d",num, uns(num));
	return 0;
}

int uns(char num[])
{
	int i,res=0;
	for(i=0;i<100;i++)
	{
		res+=(int)num[0]*pow(10,i);
	}
	return res;
}
