#include<stdio.h>
int main()
{
	int c,n,p,i;
	
	scanf("%d %d %d",&c,&n,&p);
	
	int d=1;
	
	for(i=1;i<=n;i++)
	{
		d=((d%p)*(c%p))%p;
	}
	
	printf("%d\n",d);
		 
	return 0;
}
