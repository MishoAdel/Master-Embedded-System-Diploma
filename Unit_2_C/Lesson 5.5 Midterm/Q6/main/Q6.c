/*
 ============================================================================
 Name        : Q6.c
 Author      : Misho
 Description : write c function to return unique number in array with one loop?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int unique(int num[],int size);

int main(void) {
	int nums[7],i;
	int size=sizeof(nums)/sizeof(nums[0]);
	printf("Enter array numbers: ");
	for(i=0;i<size;i++)
	{
		fflush(stdout);
		scanf("%d",&nums[i]);
	}

	printf("%d",unique(nums,size));
	return 0;
}

int unique(int nums[],int size){
	int i,res=0;
	for(i=0;i<size;i++)
		res^=nums[i];
	return res;
}
