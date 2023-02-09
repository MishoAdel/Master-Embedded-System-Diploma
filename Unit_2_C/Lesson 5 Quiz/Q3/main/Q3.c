/*
 ============================================================================
 Name        : Q3.c
 Author      : Misho
 Description : Write a C function to reverse an input array.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void rev(int arr[],int length);

int main(void) {
	int arr[7],i,length=sizeof(arr)/sizeof(arr[0]);
	printf("Input: ");
	for(i=0;i<length;i++)
	{
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	rev(arr,length);
	length=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<length;i++)
		{
			printf("%d ",arr[i]);
		}
	return 0;
}

void rev(int arr[],int length){
	int i,temp;
	for(i=0;i<length;i++)
	{
		temp=arr[i];
		arr[i]=arr[length-1];
		arr[length-1]=temp;
		length--;
	}
}
