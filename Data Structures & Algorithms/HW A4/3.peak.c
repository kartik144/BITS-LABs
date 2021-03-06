#include<stdio.h>
int peak=-1;

void findPeak(int mid,int arr[],int n)
{
	if(mid==0)
	{
		if(arr[mid]>=arr[mid+1])
		{
			peak= mid;
			return;
		}
	}
	else if(mid==n-1)
	{
		if(arr[mid]>=arr[mid-1])
		{
			peak= mid;
			return;
		}
	}
	else
	{
		if(arr[mid]>=arr[mid+1] && arr[mid]>=arr[mid-1])
		{
			peak=mid;
			return;
		}
	}
}
void peakIndex(int arr[],int l,int r,int n)
{
	//printf("*");
	if(l<r)
	{
		//printf("*");
		
		int mid=l+(r-l)/2;
		findPeak(mid,arr,n);
		
		if(r-l==1)
		findPeak(mid+1,arr,n);
		//printf("*");
		
		peakIndex(arr,l,mid,n);
		peakIndex(arr,mid+1,r,n);
	}
	
	return;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	peakIndex(arr,0,n-1,n);
	
	printf("%d\n",peak);
	
	return 0;
}
