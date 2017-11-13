#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>

sem_t s;
int counter;

void handler(void *ptr)
{
	int x;
	x=*((int *)ptr);
	printf("*Thread %d:Waiing to enter critical section...\n",x);
	sem_wait(&s);
	
	//CRITICAL SECTION
	printf("Thread %d:Now in critical section...\n",x);
	printf("Thread %d:Counter Value: %d\n",x,counter);
	printf("Thread %d:Incrementing counter...\n",x);
	counter++;
	printf("Thread %d:New counter Value: %d\n",x,counter);
	printf("Thread %d:Exiting critical section...\n",x);
	//END of CRITICAL SECTION
	
	sem_post(&s);
	pthread_exit(0);
	
}

int main()
{
	int i[]={0,1,2,3,4};
	pthread_t thrd[5];
	//i[0]=0;
	//i[1]=1;
	int j;
	sem_init(&s,0,1);
	for(j=0;j<5;j++)
	pthread_create(&thrd[j],NULL,(void *) &handler,(void *) &i[j]);
	
	for(j=0;j<5;j++)
	pthread_join(thrd[j],NULL);
	
	sem_destroy(&s);
	exit(0);
}
