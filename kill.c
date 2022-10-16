#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
int main(int argc,char *argv[])
{
	int prid,sig,ret;
	if(argc!=3)
	{
		printf("Please enter a valid input\n");
		return -1;
	}
	prid=atoi(argv[1]);
	sig=atoi(argv[2]);
	ret=kill(prid,sig);
	if(ret!=0)
	{
		printf("KILL UNSUCCESSFUL\n");
		return -1;
	}
	return 0;
}
