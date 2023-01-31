/*
 ============================================================================
 Name        : EX4.c
 Author      : Misho
 Description : Write C Program to insert an elemnet into array
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int arr[100];
	int num,loc,size,i;
	printf("Enter the number of elements : ");
	fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++){
		arr[i]=i+1;
		scanf("%d",&arr[i]);
	}
	printf("\r\nEnter the element to be inserted : ");
	fflush(stdout);
	scanf("%d",&num);
	printf("Enter the location : ");
	fflush(stdout);
	scanf("%d",&loc);
	size++;
for(i=0;i<size;i++){
		if(i+1==loc)
			arr[i]=num;
		else if(i+1>loc)
			arr[i]=i;
		printf("%d\t",arr[i]);
	}
}
