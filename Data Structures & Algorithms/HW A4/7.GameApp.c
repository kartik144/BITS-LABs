#include<stdio.h>
#include<string.h>
int main()
{	
	int test;
	scanf("%d",&test);
	
	while(test--)
	{
		int i,index=-1,j;
		char s[1000];
		scanf("%s",s);
		
		int n=strlen(s);
		
		for(i=n-1;i>=1;i--)
		if(s[i]>s[i-1])
		{
			index=i-1;
			break;
		}
		
		if(index==-1)
		printf("game terminated!\n");
		else
		{
			for(i=n-1;i>index;i--)
			if(s[i]>s[index])
			{
				char temp=s[i];
				s[i]=s[index];
				s[index]=temp;
				break;
			}
			
			for(i=n-1,j=index+1;i>(index+n-1)/2;i--,j++)
			{
				char temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
			
			printf("%s\n",s);
		}
	}
	return 0;
}
