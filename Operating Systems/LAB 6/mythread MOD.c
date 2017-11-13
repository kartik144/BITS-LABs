#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>
#define N 5

void *fun(void *k)
{
    int i;
    for(i=1;i<=10;i++)
    printf("%d ",(i+(*(int *)k)*10));
    
    printf("\n");
    
    return NULL;
    
}

int main(int argc,char *argv[])
{
    pthread_t t[N];
    int data[N],errcode,i;
    
    for(i=0;i<N;i++)
    {
        if(pthread_create(&t[i],NULL,fun,&i))
        {
            printf("Error Creating Thread!\n");
            exit(-1);
        }
        else
        pthread_join(t[i],NULL);
    }
    
    //for(i=0;i<N;i++)
    
    
    
    return 0;
}	
