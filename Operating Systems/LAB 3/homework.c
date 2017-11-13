#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int flag=1;

int main()
{
	char s[5];
	
	
	if(flag==1)
	{
		printf("$");
		gets(s);
		pid_t p;
		int status;
		
		p=fork();
		
		if(p<0)
			perror("Fork\n");
		else if(p==0)
		{
			if(strcmp(s,"cat")==0)
			execlp("cat","cat",NULL);
			else if(strcmp(s,"ls")==0)
			execlp("ls","ls",NULL);
			else if(strcmp(s,"pwd")==0)
			execlp("pwd","pwd",NULL);
			else if(strcmp(s,"exit")==0)
			{
				
				flag=0;// exit function not working!!!
			}
			else
			printf("Command not found!\n");
			
			
		}
		else
		{
			wait(&status);
			if(flag==0)
			execlp("kill","kill","-9",itoa(getpid()),NULL);
		}
	}
	
	return 0;
}
