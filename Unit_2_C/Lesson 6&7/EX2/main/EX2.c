/*
 ============================================================================
 Name        : EX2.c
 Author      : Misho
 Description : Write C program to add two distances using (foot inch) system using structures
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct dist{
	int foot;
	float inch;
}distance1,distance2,sum;
int main(void) {
	printf("Enter Information of first distance\r\n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&distance1.foot);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&distance1.inch);
	printf("Enter Information of second distance\r\n");
	printf("Enter feet: ");
	fflush(stdout);
	scanf("%d",&distance2.foot);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&distance2.inch);
	sum.foot=distance1.foot+distance2.foot;
	float inches;
	for(inches=distance1.inch+distance2.inch;inches>=12.0;inches-=12)
		sum.foot++;
	sum.inch=inches;
	printf("Sum of distances %d'%.2f",sum.foot,sum.inch);
	return 0;
}
