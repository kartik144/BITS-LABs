#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int sq=sqrt(n),i,j,sum=0;
	int arr[sq+1];
	
	for(i=0;i<=sq;i++)
	arr[i]=1;
	
	for(i=2;i<=sq;i++)
	if(arr[i]==1)
	{
		for(j=2*i;j<=sq;j+=i)
		arr[j]=0;
	}
	
	
	
	for(i=2;i<=sq;i++)
	if(arr[i]==1)
	{
		while(n%i==0)
		{
			sum++;
			n=n/i;
		}
	}
	
	printf("%d\n",sum);
	
	return 0;
}
