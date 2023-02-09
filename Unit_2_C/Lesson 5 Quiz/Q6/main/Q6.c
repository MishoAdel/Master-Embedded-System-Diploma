/*
 ============================================================================
 Name        : Q6.c
 Author      : Misho
 Description : Write a C function to return the 4th least significant bit
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int forthsign(int num);

int main(void) {
	int num;
	printf("Enter number = ");
	fflush(stdout);
	scanf("%d",&num);
	printf("%d", forthsign(num));
	return 0;
}

int forthsign(int num)
{
	if(num>=8)
	{
		num/=8;
		num%=2;
	}
	else
		num=0;
	return num;
}
