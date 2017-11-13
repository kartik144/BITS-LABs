#include<stdio.h>
#include<math.h>
void printHeap(int arr[],int n)
{
	int i;
	if(n==0)
	return;
	else
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	
	printf("\n\n");
	return;
}
void maxHeapify(int arr[],int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int largest;
	
	if(l<n && arr[l]>arr[i])
	largest=l;
	else
	largest=i;
	
	if(r<n && arr[r]>arr[largest])
	largest=r;
	
	if(largest!=i)
	{
		int temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;
		maxHeapify(arr,largest,n);
	}
	
	return;
}

void addElement(int arr[],int i,int n)
{
	int par=floor((i-1)/2.0);
//	printf("par=%d ::",par);
	if(arr[i]>arr[par] && par>=0)
	{
		int temp=arr[i];
		arr[i]=arr[par];
		arr[par]=temp;
		//printHeap(arr,n);
		addElement(arr,par,n);
	}
}

void buildMaxHeap(int arr[],int n)
{
	int i;
	
	for(i=ceil(n/2);i>=0;i--)
	maxHeapify(arr,i,n);
	
	return;
}



int main()
{
	int ch,t;
	printf("1.Enter in Heap\n2.Delete max number\n3.Find max\n4.exit\nEnter Choice: ");
	scanf("%d",&ch);
	int arr[10000],l=0;
	
	while(ch!=4)
	{
		switch(ch)
		{
			case 1: scanf("%d",&t);
				l++;
				arr[l-1]=t;
				addElement(arr,l-1,l);
				printHeap(arr,l);
				break;
			
			case 2: if(l-1<0)
				{
					printf("Underflow!\n");
					break;
				}
				arr[0]=arr[l-1];
				l--;
				maxHeapify(arr,0,l);
				printHeap(arr,l);
				break;
		
			case 3:  if(l-1<0)
				{
					printf("Underflow!\n");
					break;
				}
				printf("\n%d\n",arr[0]);
				break;
			
		}
		printf("1.Enter in Heap\n2.Delete max number\n3.Find max\n4.exit\nEnter Choice: ");
		scanf("%d",&ch);
	}
	
	return 0;
}
