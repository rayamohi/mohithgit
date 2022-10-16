#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
void *thread1(void *);
void *thread2(void *);
int max;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void main()
{
	pthread_t ti1,ti2;
	int *ptr;
	printf("Enter the MAX:\n");
	scanf("%d",&max);
	pthread_create(&ti1,NULL,thread1,&max);
	pthread_create(&ti2,NULL,thread2,&max);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}

void *thread1(void *ptr)
{
	int i;
	for(i=0;i<=max;i++)
	{
		if(i%2==0)
		{
			pthread_mutex_lock(&mutex);
			printf("even:%d\n",i);
			pthread_mutex_unlock(&mutex);
		}
		sleep(1);
	}
}


void *thread2(void *ptr)
{
	int i;
	for(i=0;i<=max;i++)
	{
		if(i%2!=0)
		{
			pthread_mutex_lock(&mutex);
			printf("odd:%d\n",i);
			pthread_mutex_unlock(&mutex);
		}
		sleep(1);
	}
}
