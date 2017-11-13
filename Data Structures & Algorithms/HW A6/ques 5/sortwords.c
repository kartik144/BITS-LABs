#include<stdio.h>
#include<string.h>
void sort (char s[])
{
	int i,j;
	int n=strlen(s);
	for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
	{
		if(s[j]>s[j+1])
		{
			char ch=s[j];
			s[j]=s[j+1];
			s[j+1]=ch;
		}
	}
}

int main()
{
	char s[50];
	scanf("%s",s);
	int i;
	
	for(i=0;i<7;i++)
	{
		char str[50];
		strcpy(str,s);
		sort(s);
		printf("%s %s\n",s,str);
		scanf("%s",s);
	}
	
	return 0;
}
