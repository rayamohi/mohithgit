#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
void main()
{
	DIR *fd;
	struct dirent *name;
	fd=opendir(".");
	while((name=readdir(fd))!=NULL)
	{
		printf("%s\t",name->d_name);
	}
}
