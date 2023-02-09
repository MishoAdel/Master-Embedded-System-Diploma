/*
 ============================================================================
 Name        : Q6.c
 Author      : Misho
 Description : write c function to return unique number in array with one loop?
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int unique(int num[]);

int main(void) {
	int nums[3],i;
	printf("Enter array numbers: ");
	for(i=0;i<3;i++)
	{
		fflush(stdout);
		scanf("%d",&nums[i]);
	}

	printf("%d",unique(nums));
	return 0;
}

int unique(int nums[]){
	int i,j,check;//if check=1 so it unique number
	for(i=0;i<3;i++)
	{
		check=1;
		for(j=0;j<3;j++)
		{

			if(nums[i]==nums[j]&&i!=j)
				{
				check=0;
				break;
				}
		}
		if (check==1)
			return nums[i];
	}
	return 0;
}
