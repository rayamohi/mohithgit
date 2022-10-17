#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread1(void *);
void *thread2(void *);
int min,max;
void main()
{
	pthread_t ti1,ti2;
	int *ptr;
	printf("Enter the minimum number:\n");
	scanf("%d",&min);
	printf("Enter the maximum number:\n");
	scanf("%d",&max);
	pthread_create(&ti1,NULL,thread1,&max);
	pthread_create(&ti2,NULL,thread2,&max);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *thread1(void *ptr)
{
	int i;
	for(i=min;i<=max;i++)
	{
		if(i%2==0)
		{
			printf("even:%d\n",i);
		}
		sleep(1);
	}
}
void *thread2(void *ptr)
{
	int i;
        for(i=min;i<=max;i++)
        {
		if(i%2!=0)
                {
                        printf("odd:%d\n",i);
                }
		sleep(1);
        }
}
