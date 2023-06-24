/*
 ============================================================================
 Name        : EX5.c
 Author      : Misho
 Description : Write a program in C to show a pointer to an array which contents are pointer to structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct emp_data{
	char name[100];
	int id;
};

int main() {
	struct emp_data emp1={"Alex",1002},emp2={"Tom",1003},emp3={"Richard",1004};

	struct emp_data *arr[]={&emp1,&emp2,&emp3};
	int i=0;
	for(i=0;i<3;i++){
		printf("Employee %d\n"
				"Name:%s\n"
				"ID:%d\n"
				"#########\n",i+1,arr[i]->name,arr[i]->id);
	}


	return 0;
}
