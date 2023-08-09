/*
 * students.h
 *
 *  Created on: Aug 6, 2023
 *      Author: mesho
 */

#ifndef STUDENTS_H_
#define STUDENTS_H_

#define DataType student_struct

typedef struct student_info{
	char first_name[50];
	char last_name[50];
	unsigned int roll;
	float gpa;
	int course_id[10];
} student_struct;

void start_system();
void display_student(DataType *ptr);
void add_student_manually();
void add_student_file();
void find_student_roll();
void find_student_name();
void find_student_course();
void delete_student_roll();
void update_student_roll();

#endif /* STUDENTS_H_ */
