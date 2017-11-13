#include<stdio.h>
int getRes(int arr[],int n,int k)
{
	int i,j,max=0,min=0,res=0;
	
	for(i=1;i<k;i++)
	{
		if(arr[i]>arr[max])
		max=i;
		else if(arr[i]<arr[min])
		min=i;
	}
	printf("%d %d\n",arr[min],arr[max]);
	res=arr[max]+arr[min];
	
	for(i=k;i<n;i++)
	{
		if(max<=i-k)
		max++;
		if(min<=i-k)
		min++;
		
		if(arr[i]>arr[max])
		max=i;
		else if(arr[i]<arr[min])
		min=i;
		
		printf("%d %d\n",arr[min],arr[max]);
		res+=arr[max]+arr[min];
	}
	
	return res;
}
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	printf("Enter k:");
	scanf("%d",&k);
	
	int res=getRes(arr,n,k);
	printf("%d\n",res);
	return 0;
}
