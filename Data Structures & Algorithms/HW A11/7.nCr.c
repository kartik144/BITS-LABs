#include<stdio.h>
int C(int n,int r)
{
	if(r==n || r==0)
	return 1;
	
	return C(n-1,r-1)+C(n-1,r);
}
int main()
{
	int n,r;
	
	printf("Enter 'n' and 'r' :");
	scanf("%d %d",&n,&r);
	
	printf("%dC%d = %d\n",n,r,C(n,r));
	
	return 0;
}
