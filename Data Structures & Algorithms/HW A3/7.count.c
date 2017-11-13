#include<stdio.h>

int countLines(char *s)
{
	FILE *fp=fopen(s,"r");
	if(fp==NULL)
	{
		printf("Error opening file \"%s\"",s);
		return -1;
	}
	
	char ch=getc(fp);
	int c=0;
	
	while(ch!=EOF)
	{
		if(ch=='\n')
		c++;
		
		ch=getc(fp);
	}
	
	return c;
}

int countChar(char *s)
{
	FILE *fp=fopen(s,"r");
	if(fp==NULL)
	{
		printf("Error opening file \"%s\"",s);
		return -1;
	}
	
	char ch=getc(fp);
	int c=0;
	
	while(ch!=EOF)
	{
		c++;
		ch=getc(fp);
	}
	
	return c;
}

int countWords(char *s)
{
	FILE *fp=fopen(s,"r");
	if(fp==NULL)
	{
		printf("Error opening file \"%s\"",s);
		return -1;
	}
	
	char ch=getc(fp);
	int c=0;
	
	while(ch!=EOF)
	{
		if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
		{
			ch=getc(fp);
			while((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
			{
				ch=getc(fp);
			}
			
			c++;
		}
		
		ch=getc(fp);
	}
	
	return c;
}

int main(int argc,char *argv[])
{
	int i;
	
	if(argc==1)
	printf("Enter file name as argument");
	else if(argc>1)
	{
		for(i=1;i<argc;i++)
		{
			printf("File : %s\n",argv[i]);
			printf("Number of lines : %d\n",countLines(argv[i]));
			printf("Number of words : %d\n",countWords(argv[i]));
			printf("Number of characters : %d\n\n",countChar(argv[i]));
			
		}
	}
	
	return 0;
}
