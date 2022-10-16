#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
void main()
{
	char name[20];
	int ret,opt;
	while(1)
	{
	printf("Please select from Below options:\n");
	printf("1.OPEN DIRECTORY\n2.CLOSE DIRECTORY\n");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1 : 
			printf("Enter directory name\n");
			scanf("%s",name);
			ret=mkdir(name,0777);
			if(ret<0)
			{
				printf("Failed to create directory\n");
			}
			else
			{
				printf("Successfully created directory\n");
			}
//			chdir("..");
			break;

		case 2 :

			ret=rmdir(name);
			if(ret<0)
			{
				printf("Failed to remove directory\n");
			}
			else
			{
				printf("Successfully removed directory\n");
			}
	}
}
}
