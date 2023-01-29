/*
 ============================================================================
 Name        : EX6.c
 Author      : Misho
 Description : Write C Program to calculate sum of natural numbers
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int n,i,sum=0;
	printf("Enter an integer : ");
	fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		sum+=i;
	printf("Sum = %d",sum);
	return 0;
}
