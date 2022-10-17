#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t con=PTHREAD_COND_INITIALIZER;
void *even_num(void *ptr);
void *odd_num(void *ptr);
int min;
int max;
void main()
{
	pthread_t ti1,ti2;
	int *ptr;
	printf("Enter Minimum Value\n");
	scanf("%d",&min);
	printf("Enter Maximum value\n");
	scanf("%d",&max);
	pthread_create(&ti1,NULL,even_num,NULL);
	pthread_create(&ti2,NULL,odd_num,NULL);
	pthread_join(ti1,&ptr);
	pthread_join(ti2,&ptr);
}
void *even_num(void *ptr)
{
	pthread_mutex_lock(&mutex);
	while(min<=max)
	{	
		if(min%2==0)
		{
			printf("T1 even : %d\n",min);
			min++;
			pthread_cond_signal(&con);
		}
		else
		{	
			pthread_mutex_unlock(&mutex);
		}
	}
	pthread_cond_signal(&con);
	pthread_exit(0);
}
void *odd_num(void *ptr)
{
	int i;
	pthread_mutex_lock(&mutex);
	while(min<=max)
	{
		if(min%2!=0)
		{
			printf("T2 odd : %d\n",min);
			min++;
			pthread_cond_wait(&con,&mutex);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
		}
	}
//	pthread_exit(0);
}
