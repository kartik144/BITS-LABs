#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	
	int i,arr[n];
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	int maxLen=0,len=0,zero=-1,index=-1;
	
	for(i=0;i<n-1;i++)
	{
		
		
		if(arr[i]==1)
		{
			index=i;
			len=0;
			
			while(arr[i]==1)
			{
				len++;
				i++;
				
				if(arr[i]==0 && arr[i+1]==1)
				{
					len++;
					zero=i;
					i++;
				}
			}
			
			if(len>maxLen)
			maxLen=len;
			else
			{
				zero=-1;
				index=-1;
			}
		}
	}
	
	if(zero>0)
	{
		printf("Index %d\n",zero);
	}
	else
	{
		if(index==0 && index+maxLen==n)
		printf("All 1's\n");
		else if(index==0)
		printf("Index %d\n",index+maxLen);
		else 
		printf("Index %d\n",index-1);
	}
	
	return 0;
}
