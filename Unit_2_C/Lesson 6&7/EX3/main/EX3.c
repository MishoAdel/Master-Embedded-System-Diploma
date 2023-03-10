/*
 ============================================================================
 Name        : EX3.c
 Author      : Misho
 Description : Write C program to add two complex numbers by passing a structure to function
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

struct complex{
	float real;
	float img;
}num1,num2,sum;

struct complex summer(struct complex,struct complex);

int main(void) {
	printf("For 1st complex number\r\n");
	printf("Enter real and imaginary numbers respectively: ");
	fflush(stdout);
	scanf("%f %f",&num1.real,& num1.img);
	printf("For 2nd complex number\r\n");
	printf("Enter real and imaginary numbers respectively: ");
	fflush(stdout);
	scanf("%f %f",&num2.real,& num2.img);
	sum=summer(num1,num2);
	printf("Sum= %.2f+%.2fi",sum.real,sum.img);
	return 0;
}

struct complex summer(struct complex num1,struct complex num2){
	struct complex sum;
	sum.real=num1.real+num2.real;
	sum.img=num1.img+num2.img;
	return sum;
}
