/*
 ============================================================================
 Name        : Q7.c
 Author      : Misho
 Description : Write a C function to return the 4th least significant bit
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pow3(int num);

int main(void) {
	int num;
	printf("Enter number = ");
	fflush(stdout);
	scanf("%d",&num);
	printf("%d ==> %d",num, pow3(num));
	return 0;
}

int pow3(int num)
{
	int i;
	for(i=1;i;i++)
	{
		if (num ==(int)pow(3,i))
			return 0;
		else if (num <(int)pow(3,i))
			return 1;
	}
}
