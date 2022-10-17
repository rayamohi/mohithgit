#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
void main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Please enter valid input\n");
		return;
	}
	int fd1,fd2,ret;
	char file1[100],file2[100];
	fd1=open(argv[1],O_CREAT|O_RDWR,0664);
	ret=read(fd1,file1,100);
	if(ret<0)
	{
		printf("Could not read from file\n");
		return;
	}
	file1[ret]='\0';
	truncate(argv[1],0);
	fd2=open(argv[2],O_CREAT|O_RDWR,0664);
        ret=read(fd2,file2,100);
	if(ret<0)
	{
		printf("Could not read from file\n");
		return;
	}
	file2[ret]='\0';
	truncate(argv[2],0);
	printf("Data Swapped\n");
	fd1=open(argv[1],O_WRONLY);
        write(fd1,file2,strlen(file2));
	fd2=open(argv[2],O_WRONLY);
        write(fd2,file1,strlen(file1));
	close(fd1);
	close(fd2);
}




