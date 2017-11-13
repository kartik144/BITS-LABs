#include<stdio.h>
int main()
{
	int a[8][8];
	int i,j;
	int flag=0,c1=0,c2=0;
	
	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	scanf("%d",&a[i][j]);
	
	for(i=0;i<8;i++)
	{
		c1=0;
		c2=0;
		
		for(j=0;j<8;j++)
		{
			if(a[i][j]==1)
			c1++;
			if(a[j][i]==1)
			c2++;
		}
		
		if(c1>1 || c2>1)
		{
			flag=1;
			break;
		}
	}
	
	/*if(flag!=1)
	for(i=0;i<8;i++)
	{
		c=0;
		
		for(j=0;j<8;j++)
		if(a[j][i]==1)
		c++;
		
		if(c>1)
		{
			flag=1;
			break;
		}
	}*/
	
	if(flag!=1)
	for(i=0;i<8;i++)
	{
		c1=0;
		c2=0;
		
		for(j=i;j<=7-i;j++)
		{
			if(a[j][j-i]==1)
			c1++;
			
			if(a[j-i][j]==1)
			c2++;
		}
		
		if(c1>1 || c2>1)
		{
			flag=1;
			break;
		}
	}
	
	if(flag!=1)
	for(i=7;i>=0;i--)
	{
		c1=0;
		c2=0;
		
		for(j=0;j<=i;j++)
		{
			if(a[j][i-j]==1)
			c1++;
			
			if(a[7-i+j][7-j]==1)
			c2++;
		}
		
		if(c1>1 || c2>1)
		{
			flag=1;
			break;
		}
	}
	
	if(flag==1)
	printf("NO\n");
	else
	printf("YES\n");
	
	return 0;
}
