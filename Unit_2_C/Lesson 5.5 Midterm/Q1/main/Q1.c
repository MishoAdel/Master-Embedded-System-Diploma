/*
 ============================================================================
 Name        : Q1.c
 Author      : Misho
 Description : write c function to take a number and sum all digits?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum(int num);

int main(void) {
	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Output=> %d",sum(num));
	return 0;
}

int sum(int num){
	int res=0;
	while(num>0){
		res+=num%10;
		num=num/10;
	}
	return res;
}
