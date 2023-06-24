/*
 ============================================================================
 Name        : EX4.c
 Author      : Misho
 Description : Write a program in C to print the elements of an array in reverse order.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[15];
	int size=1;
	int i;
	printf("Input the number of elements to store in the array (max 15) : ");
	//while(size>0 && size <16){
		fflush(stdout);
		scanf("%d",&size);
	//}
	for(i=0;i<size;i++){
		printf("Enter the Element-%d : ",i+1);
		fflush(stdout);
		scanf("%d",&arr[i]);
	}
	int* ptr=&arr[size-1];
	for(i=size-1;i>=0;i--){
		printf("Element-%d : %d\n",i+1,*ptr);
		ptr--;
		}
	return 0;
}
