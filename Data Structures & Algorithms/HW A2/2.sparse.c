#include<stdio.h>
int main()
{
	int a[6][6],i,j,count=0,temp;
	
	for(i=0;i<6;i++)
	for(j=0;j<6;j++)
	{
		scanf("%d",&a[i][j]);
		
		if(a[i][j]!=0)
		count++;
	}
	
	if(count<10)
	{
		printf("\nSparse Matrix Representation\nrow\tcolumn\tvalue\n");
		
		for(i=0;i<6;i++)
		for(j=0;j<6;j++)
		if(a[i][j]!=0)
		printf("%d\t%d\t%d\n",i,j,a[i][j]);
		
		for(i=0;i<6;i++)
		for(j=0;j<=i;j++)
		{
			//printf("%d %d\t",a[i][j],a[j][i]);
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
			//printf("%d %d\n",a[i][j],a[j][i]);
		}
		
		printf("\n");
		
		printf("\nTransposed Matrix\nrow\tcolumn\tvalue\n");
		
		for(i=0;i<6;i++)
		for(j=0;j<6;j++)
		if(a[i][j]!=0)
		printf("%d\t%d\t%d\n",i,j,a[i][j]);
	}
	else
	printf("Not Sparse\n");
	
	return 0;
}
