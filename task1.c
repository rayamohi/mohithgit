#include<stdio.h>
#include<unistd.h>
void main()
{
	char* command="objdump";
	char* flags[]={"objdump", "-t",NULL};
	printf("Print 1\n");
	int ret= execvp(command, flags);
	if(ret==-1)
	{
		printf("NOT EXECUTED PROPERLY\n");
	}
	printf("If exec is succesful it will not be printed\n");


}
