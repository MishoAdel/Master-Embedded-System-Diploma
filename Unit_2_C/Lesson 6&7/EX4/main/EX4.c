/*
 ============================================================================
 Name        : EX4.c
 Author      : Misho
 Description : Write C program to store data of 10 students in array of structure
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

struct Sstud{
	char name[100];
	int roll_num;
	float marks;
};


int main(void) {
	int i;
	struct Sstud list[10];
	for(i=0;i<10;i++){
		printf("Enter Information of student %d\n"
				"Enter Name: ",i);
			fflush(stdout);
			scanf("%s",&list[i].name);
			printf("Enter roll number: ");
			fflush(stdout);
			scanf("%d",&list[i].roll_num);
			printf("Enter Marks: ");
			fflush(stdout);
			scanf("%f",&list[i].marks);
		}
	for(i=0;i<10;i++)
		printf("\nDisplaying Information\n"
						"name: %s\n"
						"Roll: %d\n"
						"Marks: %.1f",list[i].name,list[i].roll_num,list[i].marks);
	return 0;
}



