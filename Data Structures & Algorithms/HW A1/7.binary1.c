#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	
	int c=0;
	
	while(n>0)
	{
		c+=n%2;
		n/=2;
	}
	
	printf("%d\n",c);
	return 0;
}
