#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char user_name[100]= "Misho Adel\0",input[100];//you initialize username from any source database for example
	int i,check=1;
	printf("Enter you name: ");
	fflush(stdout);
	gets(input);
	int length=strlen(user_name);
	for(i=0;i<=length ; i++)
			{
				if(input[i]!=user_name[i])
					check=0;
			}
	if(check==1)
		printf("Same name");
	else
		printf("Different name");
	return 0;
}
