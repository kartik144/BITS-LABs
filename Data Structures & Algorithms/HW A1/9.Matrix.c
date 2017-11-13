#include<stdio.h>
int main()
{
	int m,p,n;
	scanf("%d %d",&m,&p);
	
	int i,j,k;
	
	int A[m][p];
	
	for(i=0;i<m;i++)
		for(j=0;j<p;j++)
		scanf("%d",&A[i][j]);
	
	scanf("%d %d",&p,&n);
	int B[p][n];
	
	for(i=0;i<p;i++)
		for(j=0;j<n;j++)
		scanf("%d",&B[i][j]);
	
	int sum=0;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<p;k++)
			sum=sum+A[i][k]*B[k][j];
		}
	}
	
	printf("%d\n",sum);
		
	return 0;
}
