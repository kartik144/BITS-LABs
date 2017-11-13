#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>
int k=1;
void* foo(void *p)
{
	int i=*(int *)p;
	if(k>20)
		pthread_exit(NULL);
	printf("Thread %d is printing %d\n",i,k);
	sleep(2);
	k++;
	foo(p);
}

int main()
{
	int i;
	pthread_t t[2];

	pthread_create(&t[0],NULL,foo,&t[0]);
	sleep(1);
	pthread_create(&t[1],NULL,foo,&t[1]);
	sleep(1);

	for(i=0;i<2;i++)
	pthread_join(t[i],NULL);

	return 0;

}