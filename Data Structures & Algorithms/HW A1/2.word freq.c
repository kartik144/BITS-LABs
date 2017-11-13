#include <stdio.h>
#include <string.h>
int main()
{
	char ch[50];
	char s[10000];
	
	gets(ch);
	gets(s);
	
	int l1=strlen(ch),l2=strlen(s),i,j,freq=0,flag;
	
	for(i=0;i<l2;i++)
	{
		if(s[i]==ch[0])
		{
			flag =0;
			i++;
			
			for(j=1;j<l1;j++)
			{
				if(s[i]!=ch[j])
				flag=1;
				
				i++;
			}
			
			if(flag==0)
			freq++;
		}
		
		
		
	}
	
	printf("%d\n",freq);
	
	return 0;
}
