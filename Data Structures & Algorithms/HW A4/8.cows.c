#include<stdio.h>

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	
	int L[n1];
	int R[n2];
	
	for(i=0;i<n1;i++)
	L[i]=arr[i+l];
	
	for(j=0;j<n2;j++)
	R[j]=arr[j+m+1];
	
	i=0,j=0,k=l;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		
		k++;
	}
	
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	
	while(j<n2)
	{	
		arr[k]=R[j];
		j++;
		k++;
	}
	
	return;
}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		
		merge(arr,l,m,r);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n];
	
	int i,j,k,count=0;
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	mergeSort(arr,0,n-1);
	
	for(i=n-1;i>=0;i--)
	{
		j=0,k=i-1;
		while(j<=k)
		{
			if(arr[i]==arr[j]+arr[k])
			{
				count++;
				j++;
			}
			else if(arr[i]>arr[j]+arr[k])
			{	
				j++;
			}
			else if(arr[i]<arr[j]+arr[k])
			{
				k--;
			}
		}
	}
	
	printf("%d\n",count);
	return 0;
}
