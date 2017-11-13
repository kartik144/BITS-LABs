#include<stdio.h>
int main()
{
	int n,a,w,in=0,i;
	scanf("%d",&n);
	int hash[1000];
	
	for(i=0;i<n;i++)
	hash[i]=0;
	
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&w);
		hash[a]++;
		
		if(hash[w]>0)
		hash[w]--;
		else
		in++;
	}
	
	printf("%d\n",in);
	
	return 0;
}
