#include<stdio.h>

void SelectionSort(int arr[],int l,int r)
{
	int i,j;
	//printf("%d %d\n",l,r);
	if(l<r)
	for(i=l;i<r-1;i++)
	{
		//printf("%d %d\n",l,r);
		for(j=i+1;j<r;j++)
		if(arr[i]>arr[j])
		{
			//printf("%d %d",arr[j],arr[j+1]);
			int temp=arr[j];
			arr[j]=arr[i];
			arr[i]=temp;
		}
	}
	
}

void sort(int arr[],int a[],int n,int n1)
{
	int i=0,j=0,k=0;
	
	while(i<n1 && k<n)
	{
		int x=a[i];
		
		for(j=0;j<n;j++)
		{
			if(arr[j]==x)
			{
				int temp=arr[j];
				arr[j]=arr[k];
				arr[k]=temp;
				k++;
			}
		}
		
		i++;
	}
	
	SelectionSort(arr,k,n);
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int arr[n];
	
	int i;
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	int n1;
	scanf("%d",&n1);
	
	int a[n1];
	
	for(i=0;i<n1;i++)
	scanf("%d",&a[i]);
	
	sort(arr,a,n,n1);
	
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	printf("\n");
	
	return 0;
}
