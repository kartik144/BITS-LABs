#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int a[500];
	a[0]=1;
	int p=1,i,j;
	
	for(i=1;i<=n;i++)
	{
		int t,carry=0;
		for(j=0;j<p;j++)
		{
			t=a[j]*i+carry;
			a[j]=t%10;
			carry=t/10;
			//printf("%d ",);
		}
		
		while(carry>0)
		{
			//printf("IM HERE");
			a[p]=carry%10;
			carry/=10;
			p++;
		}
	}
	
	for(i=p-1;i>=0;i--)
	printf("%d",a[i]);
	
	printf("\n");
	
	return 0;
}
