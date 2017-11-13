#include<stdio.h>
int main()
{
	int n,k,j;
	scanf("%d %d",&n,&k);
	
	int arr[10],i;
	
	//Min Number
	for(i=0;i<10;i++)
	arr[i]=0;
	
	if(k==1)
	arr[1]=n;
	else
	{
		for(i=1;i<=k-1;i++)
		arr[i]=1;
		
		arr[0]=n-k+1;
	}
	
	for(j=1;j<=arr[1];j++)
	printf("1");
	
	for(i=0;i<10;i++)
	if(arr[i]>0 && i!=1)
	for(j=1;j<=arr[i];j++)
	printf("%d",i);
	
	printf(" ");
	
	//MAX Number
	for(i=0;i<10;i++)
	arr[i]=0;
	
	for(i=9;i>=(10-k);i--)
	arr[i]=1;
	
	arr[9]+=n-k;
	
	for(i=9;i>=0;i--)
	if(arr[i]>0)
	for(j=1;j<=arr[i];j++)
	printf("%d",i);
	
	printf("\n");
		
	return 0;
}
