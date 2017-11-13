#include<stdio.h>
#include<string.h>

int main()
{
	char s[]="Data Structures and Algorithms";
	int i,p=0,j,k;
	int n=strlen(s);
	//printf("%d\n",n);
	
	for(i=0;i<=n;i++)
	{
		char ch=s[i];
		
		if(ch==' ' || ch=='\0')
		{
			for(j=p,k=i-1;j<=(i+p-2)/2;j++,k--)
			{
				char temp=s[j];
				s[j]=s[k];
				s[k]=temp;
			}
			
			p=i+1;
		}
	}
	
	//printf("%s\n",s);
	
	for(i=0;i<n/2;i++)
	{
		char temp=s[i];
		s[i]=s[n-1-i];
		s[n-1-i]=temp;
	}
	
	printf("%s\n",s);
	return 0;
}
