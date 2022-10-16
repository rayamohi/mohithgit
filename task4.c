#include<stdio.h>
#include<pthread.h>
#include<stdio.h>
void *thread1(void*);
void *thread2(void*);
char str[30];
void main()
{
	pthread_t ti1,ti2;
	int *ptr;
	printf("Enter the word:\n");
	scanf("%s",str);
	pthread_create(&ti1,NULL,thread1,&str);
	pthread_create(&ti2,NULL,thread2,&str);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread1(void *ptr)
{
	int i=0;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>=97&&str[i]<=122)
		{
			printf("Thread1:%c\n",str[i]);
		}
		sleep(1);	
	}
}
void *thread2(void *ptr)
{
	int i=0;
        for(i=0;str[i]!='\0';i++)
        {
                if(str[i]>=65&&str[i]<=90)
                {
                        printf("Thread2:%c\n",str[i]);
                }
		sleep(1);
        }
}
