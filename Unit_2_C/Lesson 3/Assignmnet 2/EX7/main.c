/*
 ============================================================================
 Name        : EX6\7.c
 Author      : Misho
 Description : Write C Program to find the factorial of a number
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int n,i,fac=1;
	printf("Enter an integer : ");
	fflush(stdout);
	scanf("%d",&n);
	if(n==0)
		printf("Factorial= 1");
	else if(n<0)
		printf("Error!! Factorial of negative number doesn.t exsit");
	else{
		for(i=1;i<=n;i++)
				fac*=i;
		printf("Factorial = %d",fac);
	}
	return 0;
}
