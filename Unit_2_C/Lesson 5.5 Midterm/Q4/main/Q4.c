/*
 ============================================================================
 Name        : Q4.c
 Author      : Misho
 Description : write c function to revers digits in number?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int rev(int num);

int main(void) {
	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("%d",rev(num));
	return 0;
}

int rev(int num){
	int reversed=0;
	while(num>0)
	{
		reversed*=10;
		reversed+=num%10;
		num/=10;
	}
	return reversed;
}
