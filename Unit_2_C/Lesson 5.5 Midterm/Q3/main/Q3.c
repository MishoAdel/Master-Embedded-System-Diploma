/*
 ============================================================================
 Name        : Q3.c
 Author      : Misho
 Description : write c function to print all prime numbers between two numbers?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void prime(int start,int end);

int main(void) {
	int start,end;
	printf("Enter starting number: ");
	fflush(stdout);
	scanf("%d",&start);
	printf("Enter ending number: ");
	fflush(stdout);
	scanf("%d",&end);
	prime(start,end);
	return 0;
}

void prime(int start,int end){

	int i,j,check;//check if 1 not a prime num
	printf("Prime numbers between %d and %d: ",start,end);
	for(i=start;i<=end;i++)
	{
		check=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				check=1;
		}
		if(check==0)
			printf("%d ",i);
	}
}
