/*
 ============================================================================
 Name        : EX1.c
 Author      : Misho

 Description : Write C program to find prime numbers between two numbers using user-defined functions
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void prime_nums(int start,int end);

int main(void) {
	int start,end;
	printf("Enter two numbers(intervals): ");
	fflush(stdout);
	scanf("%d %d",&start,&end);
	printf("Prime numbers between %d and %d are :",start,end);
	prime_nums(start,end);
	return 0;
}

void prime_nums(int start,int end){
	int i,j,check;
	for(i=start;i<=end;i++){
		check=0;
		for(j=2;j<i;j++){
			if(i%j==0)
				{
				check=1;
				break;
				}
		}
		if(check==0)
			printf(" %d",i);
	}
	return;
}
