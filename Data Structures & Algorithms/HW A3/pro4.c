#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	int max = -1000;
	int is_positive = 1;
	int sum = 0;
	int i,j,k;
	int temp=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] < 0)
			{
				is_positive = 0;
			}
			sum = sum + arr[i][j];
			if(arr[i][j] > max)
			{
				max = arr[i][j];
			}
		}
	}
	if(is_positive==1)
	{
		printf("Max sum is %d\n",sum);
		exit(0);
	}
	else
	{
		if(sum > max)
		{
			max = sum;
		}
		for(i=2;i<n;i++)
		{
			int strip_sum[n-i+1][n];
			for(j=0;j<n;j++)
			{
				int temp = 0;
				for(k=0;k<i;k++)
				{
					temp = temp+arr[k][j];
				}
				strip_sum[0][j] = temp;
				for(k=1;k<n-i+1;k++)
				{
					temp+=arr[i+k-1][j] - arr[k-1][j];
					strip_sum[k][j] = temp;
				}
			}
			for(k=0;k<n-i+1;k++)
			{
				temp = 0;
				for(j=0;j<i;j++){
				temp = temp + strip_sum[k][j];
				}
				if(temp>max)
				{
					max = temp;
				}
				for(j=1;j<n-i+1;j++)
				{
					temp+=strip_sum[k][j+i-1] - strip_sum[k][j-1];
					if(temp>max)
					{
						max = temp;
					}
				}
			}

		}

	}
	printf("%d\n",max);
}