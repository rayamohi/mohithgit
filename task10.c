#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void myhandler(int);
void main()
{
	printf("PID :%d\n",getpid());
	signal(2,myhandler);
	while(1)
	{
		printf("Waiting for signal\n");
		sleep(1);
	}
}
void myhandler(int signum)
{
	printf("Signal no %d received but ignored\n",signum);
}
