/*
 * studnets.c
 *
 *  Created on: Aug 6, 2023
 *      Author: mesho
 */
#include "students.h"
#include "FIFO.h"
#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define system_size 50  //size of queue

FIFO_Queue queue1;
DataType arr[system_size]={0};

void start_system(){
	FIFO_init(&queue1, arr,system_size);
	int task=0;
	Pprintf("==============================================================================\n"
			"Welcome to student management system\n");
	while(1){
		Pprintf("Choose the task you want to perform\n"
				"1. Add the students details manually\n"
				"2. Add the student details from text file\n"
				"3. Find the student details by Roll number\n"
				"4. Find the student details by first name\n"
				"5. Find the student details by course\n"
				"6. Find the total number of students\n"
				"7. Delete the students details by roll number\n"
				"8. Update the students details by roll number\n"
				"9. Show all information\n"
				"10. To exit\n"
				"Enter your choice to perform the task : ");
		scanf("%d",&task);
		Pprintf("==============================================================================\n");
		switch(task)
		{
		case 1:
			add_student_manually();
			break;
		case 2:
			add_student_file();
			break;
		case 3:
			find_student_roll();
			break;
		case 4:
			find_student_name();
			break;
		case 5:
			find_student_course();
			break;
		case 6:
			Pprintf("==============================================================================\n"
					"[INFO] Total number of students = %d\n"
					"[INFO] You can add %d more students\n"
					"==============================================================================\n",queue1.count,system_size-queue1.count);
			break;
		case 7:
			delete_student_roll();
			break;
		case 8:
			update_student_roll();
			break;
		case 9:
			FIFO_display_all(&queue1);
			break;
		case 10:
			return;
			break;
		default:
			Pprintf("Wrong choice\n");
		}
	}
}

void display_student(DataType *ptr)  //Function to print a student using pointer to this student
{
	int i;
	Pprintf("==============================================================================\n"
			"Student First Name : %s\n"
			"Student Last Name : %s\n"
			"Student Roll Number : %d\n"
			"Student GPA : %.2f\n"
			"Courses Registered : ",ptr->first_name,ptr->last_name,ptr->roll,ptr->gpa);
	for(i=0;i<10 && ptr->course_id[i]!='\0';i++)
		Pprintf("%d ",ptr->course_id[i]);
	Pprintf("\n==============================================================================\n");
}

int exsisting_roll_number(FIFO_Queue* My_Queue,int num) // Function to check if roll number exists
{
	int i;
	DataType *My_Student=My_Queue->tail;
	for(i=0;i<My_Queue->count+1;i++)
	{
		if(My_Student->roll==num)
			return 1;
		if(My_Student == (My_Queue->base + (My_Queue->length)*sizeof(DataType) ) ) // for circular queue
			My_Student=My_Queue->base;
		My_Student++; // to navigate between students
	}
	return 0;
}

void add_student_file() //to add students data from text file
{
	FILE *ptr;
	char temp_line[250];
	char loop_char;
	char temp_element[50];
	int counter=0,i,j,k,prev_char=0;
	ptr=fopen("file.txt","r");
	if(ptr==NULL)
	{
		Pprintf("File can.t be opened\n");
		return;
	}
	while(fgets(temp_line,250,ptr)) // to read each line and put it in var temp_line
	{
		DataType My_Student;
		counter=0,prev_char=0;
		i=0;
		loop_char=temp_line[i];
		while(loop_char!='\n') // loop for every line
		{
			loop_char=temp_line[i];
			if(loop_char==' ' && counter<5) // each space is the diference between each data type
			{
				counter++;
				switch(counter)
				{
				case 1: // after first space we read roll number
					for(j=0;j<(i-prev_char);j++)
						temp_element[j]=temp_line[j+prev_char]; //copy from prev char to the char before space
					temp_element[j]=' ';
					prev_char=i+1;
					My_Student.roll=atoi(temp_element);
					break;
				case 2: // second space we read first name
					for(j=0;j<(i-prev_char);j++)
						temp_element[j]=temp_line[j+prev_char];
					temp_element[j]='\0';
					prev_char=i+1;
					strcpy(My_Student.first_name,temp_element);
					break;
				case 3: // then last name
					for(j=0;j<(i-prev_char);j++)
						temp_element[j]=temp_line[j+prev_char];
					temp_element[j]='\0';
					prev_char=i+1;
					strcpy(My_Student.last_name,temp_element);
					break;
				case 4: // then gpa
					for(j=0;j<(i-prev_char);j++)
						temp_element[j]=temp_line[j+prev_char];
					prev_char=i+1;
					My_Student.gpa=atof(temp_element);
					break;
				case 5: // then courses
					for(j=0;loop_char!='\n' && j<10;i++)
					{
						loop_char=temp_line[i];
						if(loop_char==' ') // each space is the difference between courses
						{
							for(k=0;k<(i-prev_char);k++)
							{
								temp_element[k]=temp_line[prev_char+k];
							}
							temp_element[k]=' ';
							My_Student.course_id[j]=atoi(temp_element);
							j++;
							prev_char=i+1;
						}
					}
					if(loop_char=='\n') // to get last course
					{
						for(k=0;k<(i-prev_char);k++)
						{
							temp_element[k]=temp_line[prev_char+k];
						}
						temp_element[k]=' ';
						My_Student.course_id[j]=atoi(temp_element);
						My_Student.course_id[j+1]='\0';
					}
					break;
				}
			}
			i++;
		}
		if(exsisting_roll_number(&queue1,My_Student.roll)) // if roll nummber exists do.t save
		{
			Pprintf("[ERROR] Not saved successfully because roll %d number exists\n",My_Student.roll);
		}
		else if(FIFO_full(&queue1)==FIFO_FULL) // if queue full don.t save
		{
			Pprintf("[ERROR] Not Saved Successfully because system is full\n");
		}
		else // add student to the queue
		{
			FIFO_enqueue(&queue1,&My_Student);
			Pprintf("Saved Successfully :%s\n",My_Student.first_name);
		}
	}
	Pprintf("==============================================================================\n"
			"[INFO] Total number of students = %d\n"
			"[INFO] You can add %d more students\n"
			"==============================================================================\n",queue1.count,system_size-queue1.count);
}

void add_student_manually()
{
	if(FIFO_full(&queue1)==FIFO_FULL)
	{
		Pprintf("[ERROR] Not Saved Successfully because system is full\n");
		return;
	}
	DataType My_Student;
	Pprintf("Enter the student Roll Number: ");
	scanf("%d",&My_Student.roll);
	if(exsisting_roll_number(&queue1,My_Student.roll))
	{
		Pprintf("[ERROR] Not saved successfully because roll %d number exists\n",My_Student.roll);
		return;
	}
	Pprintf("Enter the student first name: ");
	scanf("%s",My_Student.first_name);
	Pprintf("Enter the student last name: ");
	scanf("%s",My_Student.last_name);
	Pprintf("Enter the student GPA: ");
	scanf("%f",&(My_Student.gpa));
	int x,i=0;
	Pprintf("Enter your registered courses IDs\n");
	while(i<10)
	{
		Pprintf("Enter the course ID or enter 0 if you are done: ");
		scanf("%d",&x);
		if(x==0)
			break;
		My_Student.course_id[i]=x;
		i++;
	}
	if(i<9)
		My_Student.course_id[i]='\0';
	FIFO_enqueue(&queue1,&My_Student);
	Pprintf("Saved Successfully :%s\n",My_Student.first_name);
	Pprintf("==============================================================================\n"
			"[INFO] Total number of students = %d\n"
			"[INFO] You can add %d more students\n"
			"==============================================================================\n",queue1.count,system_size-queue1.count);
}

void find_student_roll()
{
	int num;
	Pprintf("Enter the Roll Number you want to search for: ");
	scanf("%d",&num);
	int i;
	DataType *My_Student=queue1.tail;
	for(i=0;i<queue1.count+1;i++)
	{
		if(My_Student->roll==num)
		{
			display_student(My_Student);
			return;
		}
		if(My_Student == (queue1.base + (queue1.length)*sizeof(DataType) ) )
			My_Student=queue1.base;
		My_Student++;
	}
	Pprintf("Roll Number not found\n");
}

void find_student_name()
{
	int found=0;
	char first_name[50];
	Pprintf("Enter the Student First Name you want to search for: ");
	scanf("%s",first_name);
	int i;
	DataType *My_Student=queue1.tail;
	for(i=0;i<queue1.count+1;i++)
	{

		if(strcmp(My_Student->first_name,first_name)==0)
		{
			display_student(My_Student);
			found=1;
		}
		if(My_Student == (queue1.base + (queue1.length)*sizeof(DataType) ) )
			My_Student=queue1.base;
		My_Student++;
	}
	if(found==0)
		Pprintf("First Name not found\n");
}

void find_student_course()
{
	int course;
	int found=0;
	Pprintf("Enter the course ID you want to search for: ");
	scanf("%d",&course);
	int i,j;
	DataType *My_Student=queue1.tail;
	for(i=0;i<queue1.count+1;i++)
	{
		for(j=0;j<10 && My_Student->course_id[j]!='\0';j++)
		{
			if(My_Student->course_id[j]==course)
			{
				display_student(My_Student);
				found=1;
			}
		}
		if(My_Student == (queue1.base + (queue1.length)*sizeof(DataType) ) )
			My_Student=queue1.base;
		My_Student++;
	}
	if(found==0)
		Pprintf("Course ID not found\n");
}

void delete_student_roll()
{
	int num;
	Pprintf("Enter the Roll Number you want to delete : ");
	scanf("%d",&num);
	int i;
	DataType *My_Student=queue1.tail;
	for(i=0;i<queue1.count+1;i++)
	{
		if(My_Student->roll==num)
		{
			DataType *Temp_p=My_Student;
			while(My_Student!=queue1.head)
			{
				Temp_p++;
				*(My_Student)=*(Temp_p);
				if(My_Student == (queue1.base + (queue1.length)*sizeof(DataType) ) )
					My_Student=queue1.base;
				My_Student++;
			}
			queue1.count--;
			queue1.head--;
			return;
		}
		if(My_Student == (queue1.base + (queue1.length)*sizeof(DataType) ) )
			My_Student=queue1.base;
		My_Student++;
	}
	Pprintf("Roll Number not found\n");
}

void update_student_roll()
{
	int num;
	Pprintf("Enter the Roll Number you want to update: ");
	scanf("%d",&num);
	int i;
	int x;
	DataType *My_Student=queue1.tail;
	for(i=0;i<queue1.count+1;i++)
	{
		if(My_Student->roll==num)
		{
			int upd;
			Pprintf("Enter the section you want to update: \n"
					"1. First Name\n"
					"2. Last Name\n"
					"3. Roll Number\n"
					"4. GPA\n"
					"5. Courses registered\n"
					"Enter your choice: ");
			scanf("%d",&upd);
			switch(upd)
			{
			case 1:
				Pprintf("Enter the student first name: ");
				scanf("%s",My_Student->first_name);
				break;
			case 2:
				Pprintf("Enter the student last name: ");
				scanf("%s",My_Student->last_name);
				break;
			case 3:
				Pprintf("Enter the student Roll Number: ");
				scanf("%d",&(My_Student->roll));
				break;
			case 4:
				Pprintf("Enter the student GPA: ");
				scanf("%f",&(My_Student->gpa));
				break;
			case 5:
				Pprintf("Enter your registered courses IDs\n");
				i=0;
				while(i<10)
				{
					Pprintf("Enter the course ID or enter 0 if you are done: ");
					scanf("%d",&x);
					if(x==0)
						break;
					My_Student->course_id[i]=x;
					i++;
				}
				if(i<9)
					My_Student->course_id[i]='\0';
				break;
			default:
				Pprintf("Wrong Choice");
			}
			Pprintf("Saved Successfully :%s\n",My_Student->first_name);
			Pprintf("==============================================================================\n"
					"[INFO] Total number of students = %d\n"
					"[INFO] You can add %d more students\n"
					"==============================================================================\n",queue1.count,system_size-queue1.count);
			return;

		}
		if(My_Student == (queue1.base + (queue1.length)*sizeof(DataType) ) )
			My_Student=queue1.base;
		My_Student++;
	}
	Pprintf("Roll Number not found\n");
}
