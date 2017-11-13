#include<stdio.h>

int getMajority(int a[],int n)
{
	int i=0,count=0,maxEl=a[0];
	
	for(i=0;i<n;i++)
	{
		if(count==0)
		{
			maxEl=a[i];
			count=1;
			continue;
		}
		
		if(a[i]==maxEl)
		count++;
		else
		count--;
	}
	
	if(count==0)
	printf("No majority Element\n");
	
	else
	{
		count=0;
		
		for(i=0;i<n;i++)
		{	
			if(maxEl==a[i])
			count++;
		}
		
		if(count>n/2)
		printf("%d\n",maxEl);
		else
		printf("No majority Element\n");
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n];
	
	int i;
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	getMajority(arr,n);
	
	return 0;
}
