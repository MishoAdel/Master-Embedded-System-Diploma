/*
 ============================================================================
 Name        : EX3.c
 Author      : Misho
 Description : Write C Program to find transpose of a matrix
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	int row,column,i,j;
	float arr[row][100];
	printf("Enter rows column of the matrix : ");
	fflush(stdout);
	scanf("%d %d",&row,&column);
	printf("Enter the element of the matrix :\r\n");
	for(i=0;i<row;i++) {
		for(j=0;j<column;j++){
			printf("Enter element a%d%d : ",i+1,j+1);
			fflush(stdout);
			scanf("%f",&arr[i][j]);
		}
	}
	printf("Entered matrix\r\n");
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%0.2f\t : ",arr[i][j]);
		}
		printf("\n");
	}
	printf("Transpose of matrix\r\n");
	for(i=0;i<column;i++){
		for(j=0;j<row;j++){
			printf("%0.2f\t : ",arr[j][i]);
		}
		printf("\n");
	}
}
