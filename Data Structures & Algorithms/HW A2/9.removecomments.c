#include<stdio.h>
int main()
{
	FILE *fp=fopen("program.c","r");
	
	if(fp==NULL)
	{
		printf("Could not open file\n");
		return 0;
	}
	
	char ch;
	ch=getc(fp);
	int flag=0;
	
	while(ch!=EOF)
	{
		flag=0;
		
		if(ch=='/')
		{
			ch=getc(fp);
			
			if(ch=='/')
			{
				while(ch!='\n')
				ch=getc(fp);
				
				flag=1;
			}
			if(ch=='*')
			{
				ch=getc(fp);
				
				while(1)
				{
				
					if(ch=='*')
					{
						ch=getc(fp);
						if(ch=='/')
						break;
					}
				
					ch=getc(fp);
				}
				ch=getc(fp);
			}
			else if(flag==0)
			printf("/%c",ch);
		}
		else
		printf("%c",ch);
		
		if(flag==1)
		printf("\n");
		
		ch=getc(fp);
	}
	
	fclose(fp);
		
	return 0;
}
