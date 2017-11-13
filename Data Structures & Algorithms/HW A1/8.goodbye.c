#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	char g[]={'g','o','o','d','b','y','e'};
	
	scanf("%s",s);
	int i,j=0;
	
	for(i=0;i<strlen(s) && j<7;i++)
	{
		if(s[i]==g[j])
		j++;
	}
	
	if(j==7)
	printf("Yes\n");
	else
	printf("No\n");
	
	return 0;
}
