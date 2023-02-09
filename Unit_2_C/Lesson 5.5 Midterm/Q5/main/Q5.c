/*
 ============================================================================
 Name        : Q5.c
 Author      : Misho
 Description : write c function to ount number of ones in binary number?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int counter(int num);

int main(void) {
	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("%d",counter(num));
	return 0;
}

int counter(int num){
	int count=0;
	while(num>0)
	{
		if(num%2==1)
			count++;
		num/=2;
	}
	return count;
}
