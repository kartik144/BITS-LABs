#include<stdio.h>
#include<math.h>
typedef struct structure
{	
	int val,x,y;
}Heap;

int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int parent(int i)
{
	return floor(i/2.0)-1;
}
void maxHeapify(Heap arr[],int i,int n)
{
	int l=left(i);
	int r=right(i);
	int largest;
	
	if(l<n && arr[l].val>arr[i].val)
	largest=l;
	else largest =i;
	
	if(r<n && arr[r].val>arr[largest].val)
	largest=r;
	
	if(largest !=i)
	{
		Heap temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxHeapify(arr,largest,n);
	}

	return;
}

void buildMaxHeap(Heap arr[],int n)
{
	int i;
	
	for(i=ceil(n/2);i>=0;i--)
	maxHeapify(arr,i,n);
	
	return;
}
	
int main()
{
	int n,m,i,j;
	
	scanf("%d %d",&n,&m);
	int a[100][100]={-1};
	Heap arr[n];
	
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	scanf("%d",&a[i][j]);
	
	for(i=0;i<n;i++)
	a[i][m]=-1;
	
	i=0,j=0;
	
	for(i=0;i<n;i++)
	{
		arr[i].val=a[i][0];
		arr[i].x=i;
		arr[i].y=0;
	}
	
	buildMaxHeap(arr,n);
	
	i=0;
	j=1;
	int k=0;
	
	while(i<n*m)
	{
		printf("%d %d %d\n",arr[k].val,arr[k].x,arr[k].y);
		arr[k].val=a[i][j];
		arr[k].x=i;
		arr[k].y=j;
		j++;
		
		if(j==m)
		{
			i++;
			j=1;
		}
		
		buildMaxHeap(arr,n);
	}
	
	return 0;
}
