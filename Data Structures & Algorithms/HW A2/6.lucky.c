#include<stdio.h>
#include<math.h>
int main()
{
	long long int n,copy;
	scanf("%lld",&n);
	copy=n;
	
	int c=0,i,l=0,sum=0,k;
	
	while(copy!=0)
	{
		l++;
		copy/=10;
	}
	
	for(i=1;i<l;i++)
	c+=pow(3,i);
	
	copy=n;
	
	for(i=l-1;i>=0;i--,copy%=(int)pow(10,i+1))
	{
		k=copy/(int)pow(10,i);
		//printf("%d %d \n",k,i);
		
		if(k==1)
		{
			if(k==copy)
			c++;
			
			continue;
		}
		else if(k>1&& k<7)
		{
			c+=(int)pow(3,i);
			break;
		}
		else if(k==7)
		{
			c+=(int)pow(3,i);
			continue;
		}
		else if(k>7 && k<9)
		{
			c+=2*(int)pow(3,i);
			break;
		}
		else if(k>=9)
		{
			c+=2*(int)pow(3,i);
			if(k==copy)
			c+=3;
			
			continue;
		}
	}
	
	printf("%d\n",c);
	
	return 0;
}
	
