/*
 ============================================================================
 Name        : EX1.c
 Author      : Misho
 Description : Write C Program to find the sum of two arrays
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>

int main(){
	float x[2][2],y[2][2];
	int i,j;
	printf("Enter the elements of first matrix\r\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a%d%d : ",i+1,j+1);
			fflush(stdout);
			scanf("%f",&x[i][j]);
		}
	}
	printf("Enter the elements of second matrix\r\n");
		for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				printf("Enter b%d%d : ",i+1,j+1);
				fflush(stdout);
				scanf("%f",&y[i][j]);
			}
		}
		printf("Sum of Matrix\r\n");
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					printf("%0.2f \t",x[i][j]+y[i][j]);
				}
				printf("\r\n");
			}
}
