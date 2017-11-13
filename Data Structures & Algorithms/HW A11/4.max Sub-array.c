#include<stdio.h>
int maxOf2(int a,int b)
{
	return a>b?a:b;
}

int max(int a,int b,int c)
{
	return maxOf2(maxOf2(a,b),c);
}

int maxCrossingSum(int arr[],int l,int m,int r)
{
	int maxL=arr[m],sum=arr[m],maxR=arr[m+1];
	int i;
	
	for(i=m-1;i>=0;i--)
	{
		sum+=arr[i];
		if(sum>maxL)
		maxL=sum;
	}
	
	sum=arr[m+1];
	
	for(i=m+2;i<=r;i++)
	{
		sum+=arr[i];
		if(sum>maxR)
		maxR=sum;
	}
	
	return maxL+maxR;
}

int maxSubArray(int arr[],int l,int r)
{
	if(l==r)
	return arr[l];
	
	int m=(l+r)/2;
	
	return max(maxSubArray(arr,l,m),maxSubArray(arr,m+1,r),maxCrossingSum(arr,l,m,r));
}

int main()
{
	int n,i;
	
	printf("Enter 'n': ");
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	printf("%d\n",maxSubArray(arr,0,n-1));
	
	return 0;
}
