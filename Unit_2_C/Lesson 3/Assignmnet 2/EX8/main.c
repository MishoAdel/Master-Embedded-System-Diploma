/*
 ============================================================================
 Name        : EX8.c
 Author      : Misho
 Description : Write C Program to make simple calculator
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	float x,y;
	char op;
	printf("Enter operator either + or - or * or / : ");
	fflush(stdout);
	scanf("%c",&op);
	printf("Enter two operands : ");
	fflush(stdout);
	scanf("%f %f",&x,&y);
	switch(op){
	case '+':
		printf("%f+%f = %f",x,y,x+y);
		break;
	case '-':
		printf("%f-%f = %f",x,y,x-y);
		break;
	case '*':
		printf("%f*%f = %f",x,y,x*y);
		break;
	case '/':
		printf("%f/%f = %f",x,y,x/y);
		break;
	default:
		printf("Wrong Operator");
	}
	return 0;
}
