/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho
 Description : Write C Program to calculate average using arrays
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int n,i;
	float arr[100];
	float sum=0;
	printf("Enter the number : ");
	fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("%d. Enter number : ",i+1);
		fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
	printf("Average = %0.2f",sum/n);
}
