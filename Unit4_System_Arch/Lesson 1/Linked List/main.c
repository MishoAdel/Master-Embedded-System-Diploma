/*
 * main.c
 *
 *  Created on: Jul 24, 2023
 *      Author: mesho
 */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"

#define Pprintf(...)	{fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}

struct S_Data{
	char name[40];
	unsigned int ID;
	float height;
};

struct S_Student {
	struct S_Data Student_Data;
	struct S_Student* P_NextStudent;
};

#define DataType uint32_t

void AddStudent();
void GetData(struct S_Student* My_Student);
void DeleteStudent();
void ViewStudents();
void ViewOneStudent();
void DeleteAll();
void ReverseList();
int FindLength();
void GetMiddle();
void Sort();

struct S_Student *FirstStudent=NULL;

int main(){
	unsigned option=0;
	while(1){
		Pprintf("Choose one of the following options\n"
				"1- Add Student\n"
				"2- Delete Student\n"
				"3- View Students\n"
				"4- View one student\n"
				"5- Delete all\n"
				"6- Reverse List\n"
				"7- Find length of list\n"
				"8- Get the middle of the list\n"
				"9- Sort the list by ID\n"
				"Enter your option : ");
		scanf("%d",&option);
		switch(option){
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			ViewStudents();
			break;
		case 4:
			ViewOneStudent();
			break;
		case 5:
			DeleteAll();
			break;
		case 6:
			ReverseList();
			break;
		case 7:
			Pprintf("The Length = %d\n",FindLength())
			break;
		case 8:
			GetMiddle();
			break;
		case 9:
			Sort();
			break;
		default:
			printf("Wrong Option\n");
			break;
		}
	}
	return 0;
}

void GetData(struct S_Student* My_Student){
	Pprintf("Enter the student name: ");
	gets(My_Student->Student_Data.name);
	Pprintf("Enter the student ID: ");
	scanf("%d",&My_Student->Student_Data.ID);
	Pprintf("Enter the student height: ");
	scanf("%f",&My_Student->Student_Data.height);
}

void AddStudent(){
	if(FirstStudent==NULL)
	{
		FirstStudent=(struct S_Student*)malloc(sizeof(struct S_Student));
		GetData(FirstStudent);
		FirstStudent->P_NextStudent=NULL;
	}
	else
	{
		struct S_Student* My_Student=FirstStudent;
		while(My_Student->P_NextStudent!=NULL){
			My_Student=My_Student->P_NextStudent;
		}
		My_Student->P_NextStudent=(struct S_Student*)malloc(sizeof(struct S_Student));
		My_Student=My_Student->P_NextStudent;
		GetData(My_Student);
		My_Student->P_NextStudent=NULL;
	}
}

void DeleteStudent(){
	int ID_del;
	Pprintf("Enter the ID of the student you want to delete : ");
	scanf("%d",&ID_del);
	if(FirstStudent==NULL)
		return;
	struct S_Student* prevStudent=FirstStudent;
	struct S_Student* My_Student=FirstStudent->P_NextStudent;
	if(FirstStudent->Student_Data.ID==ID_del)
	{
		FirstStudent=FirstStudent->P_NextStudent;
		free(prevStudent);
		return;
	}
	else if(My_Student->Student_Data.ID==ID_del)
	{
		prevStudent->P_NextStudent=My_Student->P_NextStudent;
		prevStudent=My_Student;
		My_Student=My_Student->P_NextStudent;
		free(prevStudent);
		return;
	}
	do{
		prevStudent=My_Student;
		My_Student=My_Student->P_NextStudent;
		if(My_Student->Student_Data.ID==ID_del)
		{
			prevStudent->P_NextStudent=My_Student->P_NextStudent;
			free(My_Student);
			return;
		}
	}while(My_Student->P_NextStudent!=NULL);
	Pprintf("ID not found\n\n");
}

void ViewOneStudent(){

	int ID_view;
	Pprintf("Enter the ID of the student you want to view : ")
	scanf("%d",&ID_view);
	struct S_Student* My_Student=FirstStudent;
	if(FirstStudent==NULL)
		return;
	if(FirstStudent->Student_Data.ID==ID_view)
	{
		Pprintf("============================\n"
				"Student Name : %s\n"
				"Student ID : %d\n"
				"Student Height ; %f\n"
				"============================\n",FirstStudent->Student_Data.name,
				FirstStudent->Student_Data.ID,
				FirstStudent->Student_Data.height);
		return;
	}
	do{
		My_Student=My_Student->P_NextStudent;
		if(My_Student->Student_Data.ID==ID_view)
		{
			Pprintf("============================\n"
					"Student Name : %s\n"
					"Student ID : %d\n"
					"Student Height ; %f\n"
					"============================\n",My_Student->Student_Data.name,
					My_Student->Student_Data.ID,
					My_Student->Student_Data.height);
			return;
		}
	}while(My_Student->P_NextStudent!=NULL);
	Pprintf("Student Not Found\n");
}

void ViewStudents(){
	struct S_Student* My_Student=FirstStudent;
	if(FirstStudent==NULL)
		return;
	else
	{
		Pprintf("============================\n"
				"Student Name : %s\n"
				"Student ID : %d\n"
				"Student Height ; %f\n"
				"===========================\n",My_Student->Student_Data.name,
				My_Student->Student_Data.ID,
				My_Student->Student_Data.height);
	}

	while(My_Student->P_NextStudent!=NULL)
	{
		My_Student=My_Student->P_NextStudent;
		Pprintf("============================\n"
				"Student Name : %s\n"
				"Student ID : %d\n"
				"Student Height ; %f\n"
				"===========================\n",My_Student->Student_Data.name,
				My_Student->Student_Data.ID,
				My_Student->Student_Data.height);
	}
}

void DeleteAll()
{
	struct S_Student* My_Student=FirstStudent;
	struct S_Student* prevStudent;
	if(FirstStudent==NULL)
		return;
	while(My_Student->P_NextStudent!=NULL)
	{
		prevStudent=My_Student;
		My_Student=My_Student->P_NextStudent;
		free(prevStudent);
	}
	FirstStudent=NULL;
}

void ReverseList()
{
	if(FirstStudent==NULL || FirstStudent->P_NextStudent==NULL)
		return;
	struct S_Student* P_1=FirstStudent;
	struct S_Student* P_2=FirstStudent->P_NextStudent;
	struct S_Student* P_temp=FirstStudent->P_NextStudent;
	P_temp=P_temp->P_NextStudent;
	P_2->P_NextStudent=P_1;
	FirstStudent->P_NextStudent=NULL;
	while(P_temp!=NULL)
	{
		P_1=P_2;
		P_2=P_temp;
		P_temp=P_temp->P_NextStudent;
		P_2->P_NextStudent=P_1;
	}
	FirstStudent=P_2;
}

int FindLength()
{
	struct S_Student* My_Student=FirstStudent;
	if(FirstStudent==NULL)
		return 0;
	else if(FirstStudent->P_NextStudent==NULL)
		return 1;
	unsigned int count=1;
	while(My_Student->P_NextStudent!=NULL){
		count++;
		My_Student=My_Student->P_NextStudent;
	}
	return count;
}

void GetMiddle()
{
	if(FirstStudent==NULL)
	{
		Pprintf("Empty List\n");
		return;
	}
	else if(FirstStudent->P_NextStudent==NULL)
	{
		Pprintf("============================\n"
				"Student Name : %s\n"
				"Student ID : %d\n"
				"Student Height ; %f\n"
				"===========================\n",FirstStudent->Student_Data.name,
				FirstStudent->Student_Data.ID,
				FirstStudent->Student_Data.height);
		return;
	}
	struct S_Student* fast_P=FirstStudent;
	struct S_Student* slow_P=FirstStudent;
	while(fast_P!=NULL && fast_P->P_NextStudent!=NULL)
	{
		fast_P=fast_P->P_NextStudent;
		fast_P=fast_P->P_NextStudent;
		slow_P=slow_P->P_NextStudent;
	}
	Pprintf("============================\n"
			"Student Name : %s\n"
			"Student ID : %d\n"
			"Student Height ; %f\n"
			"===========================\n",slow_P->Student_Data.name,
			slow_P->Student_Data.ID,
			slow_P->Student_Data.height);
}

void Sort()
{
	if(FirstStudent==NULL || FirstStudent->P_NextStudent==NULL)
		return;
	struct S_Student* loop1_P=FirstStudent;
	struct S_Student* loop2_P=FirstStudent->P_NextStudent;
	struct S_Student* prev_P1=FirstStudent;
	struct S_Student* prev_P2=FirstStudent;
	struct S_Student* temp_P=NULL;
	int i,j,count=FindLength();
	for(i=count;i>1;i--)
	{
		for(j=1;j<i;j++)
		{
			if(loop1_P->Student_Data.ID>loop2_P->Student_Data.ID)
			{

				if(loop1_P==prev_P2)
				{
					temp_P=loop2_P->P_NextStudent;
					loop2_P->P_NextStudent=loop1_P;
					loop1_P->P_NextStudent=temp_P;
					if(loop1_P==FirstStudent)
					{
						FirstStudent=loop2_P;
					}
					else
						prev_P1->P_NextStudent=loop2_P;
					temp_P=loop1_P;
					loop1_P=loop2_P;
					loop2_P=temp_P;
				}
				else
				{
					temp_P=loop2_P->P_NextStudent;
					loop2_P->P_NextStudent=loop1_P->P_NextStudent;
					prev_P2->P_NextStudent=loop1_P;
					loop1_P->P_NextStudent=temp_P;
					if(loop1_P==FirstStudent)
						FirstStudent=loop2_P;
					else
						prev_P1->P_NextStudent=loop2_P;
					temp_P=loop1_P;
					loop1_P=loop2_P;
					loop2_P=temp_P;
				}
			}
			prev_P2=loop2_P;
			loop2_P=loop2_P->P_NextStudent;
		}
		prev_P1=loop1_P;
		loop1_P=loop1_P->P_NextStudent;
		loop2_P=loop1_P->P_NextStudent;
		prev_P2=loop1_P;
	}
}
