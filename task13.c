#include<stdio.h>
#include<unistd.h>
void main()
{
	int ret,pid;
	int fd[2];
	char rbuf[30],wbuf[30];
	ret=pipe(fd);
	if(ret==-1)
	{
		printf("Pipe not created\n");
	}
	pid=fork();
	while(1)
	{
	if(pid==0)
	{
		read(fd[0],rbuf,sizeof(rbuf));
		printf("Message received from parent : %s\n",rbuf);
	}
	else
	{
		printf("Please enter message to child : \n");
		scanf("%s",wbuf);
		write(fd[1],wbuf,sizeof(wbuf));
		sleep(1);
	}
	}
}

