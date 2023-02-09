/*
 ============================================================================
 Name        : Q2.c
 Author      : Misho
 Description : Write C program two swap two arrays with different length
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr1[10],arr2[10],i,temp;
	printf("Enter the first array: ");
	for(i=0;i<10;i++)
	{
		fflush(stdout);
		scanf("%d",&arr1[i]);
	}
	printf("Enter the second array: ");
	for(i=0;i<7;i++)
	{
		fflush(stdout);
		scanf("%d",&arr2[i]);
	}
	for(i=0;i<10;i++)
	{
		temp=arr1[i];
		arr1[i]=arr2[i];
		arr2[i]=temp;
	}

	printf("First Array :");
	for(i=0;i<7;i++)
	{
		printf("%d ",arr1[i]);
	}
	printf("\r\n");
	printf("Second Array :");
	for(i=0;i<10;i++)
	{
		printf("%d ",arr2[i]);
	}
	printf("\r\n");
	return 0;
}
