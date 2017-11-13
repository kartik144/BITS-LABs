#include<stdio.h>

int partition(int arr[],int l,int r)
{
	int x=arr[r];
	int i,j=l-1;
	
	for(i=l;i<r;i++)
	{
		if(arr[i]%10<=x%10)
		{
			j++;
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	
	int temp=arr[j+1];
	arr[j+1]=x;
	arr[r]=temp;
	
	return j+1;
}

void sort(int arr[],int l,int r)
{
	//printf("%d %d\n",l,r);
	if(l<r)
	{
		int m=partition(arr,l,r);
		sort(arr,l,m-1);
		sort(arr,m+1,r);
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
	
	sort(arr,0,n-1);
	
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	printf("\n");
	
	return 0;
}
