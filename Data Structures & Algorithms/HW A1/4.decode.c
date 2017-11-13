#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	int i,p=0,j;
	
	gets(s);
	
	for(i=0;i<=strlen(s);i++)
	{
		if(s[i]==' ' || s[i]=='\0')
		{
			for(j=i-1;j>=p;j--)
			{
				char ch=(char)(s[j]+3);
				
				if(ch>'z')
				ch=(char)(ch-26);
				
				printf("%c",ch);
			}
			
			p=i+1;
			printf(" ");
		}
	}
	
	printf("\n");
	
	return 0;
}
