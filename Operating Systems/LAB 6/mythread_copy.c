#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 5

int sum=0;

void *fun()
{
    int i;
    while(1);
    
    
}

int main(int argc,char *argv[])
{
    pthread_t t[N];
    int data[N],errcode,i;
    
    for(i=0;i<N;i++)
    {
        //data[i]=atoi(argv[i+1]);
        if(pthread_create(&t[i],NULL,fun,NULL))
        {
            printf("Error Creating Thread!\n");
            exit(-1);
        }
    }
    
    for(i=0;i<N;i++)
    pthread_join(t[i],NULL);
    
    printf("Sum: %d\n",sum);
    
    return 0;
}
