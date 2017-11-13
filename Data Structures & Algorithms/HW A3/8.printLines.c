#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int countLines(char *s)
{
	int c=0;
	FILE *fp=fopen(s,"r");
	char ch=getc(fp);
	
	while(ch!=EOF)
	{
		if(ch=='\n')
		c++;
		
		ch=getc(fp);
	}
	
	return c;
}

int printLines(char *file,int n,char *dir)
{
	FILE *fp=fopen(file,"r");
	int i;
	char s[10000];
	
	if(strcmp(dir,"t")==0)
	{
		for(i=0;i<n;i++)
		{
			fgets(s,1000,fp);
			printf("%s",s);
		}
	}
	else
	{
		for(i=1;i<=countLines(file)-n;i++)
		fgets(s,1000,fp);
		
		for(i=1;i<=n;i++)
		{
			fgets(s,1000,fp);
			printf("%s",s);
		}
	}
}

int main(int argc,char *argv[])
{
	//printf("*\n");
	if((argc==4 && argv[1][0]!='-') || argc<3)
	{
		printf("Usage:./a.out -numlines filename t\n");
		return 0;
	}
	
	if(argv[1][0]=='-')
	{
		int i=1,n=countLines(argv[2]);
		char num[1000];
		
		for(i=1;i<=strlen(argv[1]);i++)
		num[i-1]=argv[1][i];
		
		int n1=atoi(num);
		
		if(n<n1)
		printLines(argv[2],n,argv[3]);
		else
		printLines(argv[2],n1,argv[3]);
	}
	else
	{
		int n=countLines(argv[1]);
		
		if(n<10)
		printLines(argv[1],n,argv[2]);
		else
		printLines(argv[1],10,argv[2]);
	}
	
	return 0;
}
