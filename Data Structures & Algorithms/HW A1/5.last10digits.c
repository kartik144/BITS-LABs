#include<stdio.h>
int main()
{
	int n,i;
	scanf("%d",&n);
	
	long long int dig=1;
	
	for(i=1;i<=n;i++)
	dig=(dig*2)%10000000000;
	
	printf("%lld\n",dig);
	
	return 0;
}
