/*
 ============================================================================
 Name        : EX1.c
 Author      : Misho
 Description : Write C program to handle Pointers
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m=29;
	printf("Address of m : %x\nValue of m : %d\n",&m,m);
	int* ab=&m;
	printf("Now ab i assigned by the address of m\n"
			"Address of pointer ab : %x\n"
			"Value of the pointer ab : %d\n",ab,*ab);
	m=34;
	printf("Now the value of m i assigned to 34\n"
				"Address of pointer ab : %x\n"
				"Value of the pointer ab : %d\n",ab,*ab);
	*ab=7;
	printf("The pointer of the variable ab is assigned with the value 7 now\n"
				"Address of pointer ab : %x\n"
				"Value of the pointer ab : %d\n",ab,*ab);
	return 0;
}
