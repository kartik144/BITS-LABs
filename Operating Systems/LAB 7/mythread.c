#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>
#define N 5
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
int j=0;

void *fun(void *k)
{
    int i;
    pthread_mutex_lock(&lock);
    int t=*((int *)k);
    for(i=1;i<=10;i++);
    printf("%d ",(i+j*10));
    
    printf("\n");
    j++;
    pthread_mutex_unlock(&lock);
    return NULL;
    
}

int main(int argc,char *argv[])
{
    pthread_t t[N];
    int data[N],errcode,i;
    int arr[]={1,2,3,4,5};
    for(i=0;i<N;i++)
    {
        if(pthread_create(&t[i],NULL,fun,&arr[j]))
        {
            printf("Error Creating Thread!\n");
            exit(-1);
        }
    }
    
    for(i=0;i<N;i++)
    pthread_join(t[i],NULL);
    
    
    return 0;
}
