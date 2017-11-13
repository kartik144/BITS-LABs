#include<stdio.h>

void partitionEvenOdd(int arr[],int n)
{
	int i=0,j=n-1;
	
	while(i!=j)
	{
		while(arr[j]%2!=0 && i!=j)
		j--;
		
		while(arr[i]%2!=1 && i!=j)
		i++;
		
		if(i<j)
		{
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
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
	
	partitionEvenOdd(arr,n);
	
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	printf("\n");
	
	return 0;
}
