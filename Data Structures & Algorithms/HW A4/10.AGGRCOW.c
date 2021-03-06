#include<stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	
	while(test--)
	{
		int n,i,c;
		scanf("%d %d",&n,&c);
		
		long long int arr[n];
		
		long long int low=1;
		long long int high=arr[n-1];
		long long int mid;
		
		for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
		
		while(high-low>1)
		{
			int count=1;
			int index=0;
			mid=low+(high-low)/2;
			
			for(i=1;i<n;i++)
			{
				if(arr[i]-arr[index]>=mid)
				{
					index=i;
					count++;
				}
			}
			
			if(count<c)
			{
				high=mid;
				continue;
			}
			else if(count>=c)
			{
				low=mid;
				continue;
			}
		}
		
		printf("%lld\n",low);
	}
	
	return 0;
}
