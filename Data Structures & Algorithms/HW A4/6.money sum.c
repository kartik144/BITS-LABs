#include<stdio.h>

void merge(int arr[],int l,int r,int mid)
{
	int i,j,k;
	int n1=mid-l+1;
	int n2=r-mid;
	
	int L[n1];
	int R[n2];
	
	for(i=0;i<n1;i++)
	L[i]=arr[i+l];
	
	for(j=0;j<n2;j++)
	R[j]=arr[mid+1+j];
	
	i=0;
	j=0;
	k=l;
	
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
		int mid=l+(r-l)/2;
		
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		
		merge(arr,l,r,mid);
	}
}

int binarySearch(int arr[],int l,int r,int key)
{
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]>key)
		{
			r=mid-1;
			continue;
		}
		else if(arr[mid]<key)
		{
			l=mid+1;
			continue;
		}
	}
	
	return -1;
}

int main()
{
	int n,x,i,index=-2;
	scanf("%d %d",&n,&x);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	mergeSort(arr,0,n-1);
	
	for(i=0;i<n;i++)
	{
		int temp=x-arr[i];
		
		if(temp>0)
		index=binarySearch(arr,0,n,temp);
		
		if(index>=0)
		break;
	}
	
	if(index>=0)
	printf("YES\n");
	else
	printf("NO\n");
	
	return 0;
}
