#include<stdio.h>
#include<limits.h>
void toZero(int a[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	a[i]=0;
	
	return;
}

int kadane(int arr[],int n,int size)
{
	int sum=0,maxSum=INT_MIN,i,flag=-1;
	
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		
		if(i>size)
		{
			sum-=arr[i-size-1];
			
			if(sum>maxSum && sum>0)
			{
				maxSum=sum;
				flag=i;
			}
		}
		
	}
	
	if(flag!=-1)
	return maxSum;
	else
	{
		maxSum=arr[0];
	
		for(i=1;i<n;i++)
		if(arr[i]>maxSum)
		maxSum=arr[i];
	
		//printf("* %d %d %d \n",start,flag,size);
	
		return maxSum;
	}
}

int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	
	int arr[n][n];
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&arr[i][j]);
	
	int maxSum=INT_MIN;
	int temp[n],sum;

	for(i=0;i<n;i++)
	{
		toZero(temp,n);
		
		for(j=i;j<n;j++)
		{	
			for(k=0;k<n;k++)
			temp[k]+=arr[k][j];
			
			sum=kadane(temp,n,j-i);
			
			if(sum>maxSum)
			maxSum=sum;
		}
	}
	
	printf("%d\n",maxSum);
	
	return 0;
}
