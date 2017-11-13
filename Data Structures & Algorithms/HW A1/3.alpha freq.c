#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000];
	gets(s);
	char arr[1000];
	int a[1000];
	int i,j,v=0,flag;
	
	for(i=0;i<strlen(s);i++)
	{
		char ch=s[i];
		flag=0;
		
		for(j=0;j<v;j++)
		if(ch==arr[j])
		{
			a[j]++;
			flag=1;
			break;
		}
		
		if(flag==0)
		{
			arr[v]=ch;
			a[v]=1;
			v++;
		}
	}
	
	for(i=0;i<v;i++)
	printf("%c %d\n",arr[i],a[i]);
	
	return 0;
}
