/*
 ============================================================================
 Name        : Q10.c
 Author      : Misho
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int max_ones(int num);

int main(void) {
	int num;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%d",&num);
	int count=max_ones(num);
	printf("%d",count);
	return 0;
}

int max_ones(int num){
	int i,n,bin[256],count=0;
	for(i=0;i<256;i++){
		bin[i]=num%2;
		num/=2;
	}
	for(i=0;i<256;i++)
		if(i==0)
		{
			for(n=1;bin[i+n]==1;n++){
				if(n>count)
					count=n;
			}
		}
	return count;

}
