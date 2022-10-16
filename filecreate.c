#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
void main()
{
	FILE *fd;
	char name[30];
	printf("Enter File name to create\n");
	scanf("%s",name);
	fd=fopen(name,"w");
	if(fd==NULL)
	{
		printf("File not created successfully\n");
	}
	printf("File created successfully\n");
	fclose(fd);
}
