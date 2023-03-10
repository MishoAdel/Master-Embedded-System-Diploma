/*
 ============================================================================
 Name        : Q1.c
 Author      : Misho
 Description : Write C program to store information (name, roll and marks)of a Studnet using structure
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
	struct Sstud student1;
	printf("Enter Information of students\r\n"
			"Enter Name: ");
	fflush(stdout);
	gets(student1.name);
	printf("Enter roll number: ");
	fflush(stdout);
	scanf("%d",&student1.roll_num);
	printf("Enter Marks: ");
	fflush(stdout);
	scanf("%f",&student1.marks);
	printf("\r\nDisplaying Information\r\n"
			"name: %s\r\n"
			"Roll: %d\r\n"
			"Marks: %f",student1.name,student1.roll_num,student1.marks);
	return 0;
}
