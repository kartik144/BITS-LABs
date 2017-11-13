#include<stdio.h>
#include<limits.h>
int minCoins(int arr[],int n,int N)
{
	int i,table[N+1];
	
	table[0]=0;
	
	for(i=1;i<=N;i++)
	table[i]=INT_MAX;
	
	for (int i=1; i<=N; i++)
	{
	       
		for (int j=0; j<n; j++)
		if (arr[j] <= i)
		{
			int sub_res = table[i-arr[j]];
			
			if (sub_res != INT_MAX && sub_res + 1 < table[i])
			table[i] = sub_res + 1;
		}
	}
	return table[N];
}
int main()
{
	int n,i,N;
	
	printf("Enter 'n': ");
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	printf("Enter 'N': ");
	scanf("%d",&N);
	
	printf("%d\n",minCoins(arr,n,N));
	
	return 0;
}
