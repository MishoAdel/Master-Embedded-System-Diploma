/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Description : Write C Program to search an elemnet in an array
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int arr[100];
	int num,size,i;
	printf("Enter the number of elements : ");
	fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++){
		arr[i]=i+1;
		scanf("%d",&arr[i]);
	}
	printf("\r\nEnter the element to be searched : ");
	fflush(stdout);
	scanf("%d",&num);
	for(i=0;i<size;i++){
			if(arr[i]==num)
				break;
		}
			printf("Number %d found at %d",arr[i],i+1);
}
