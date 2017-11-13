#include<stdio.h>
int power(int x,int y)
{
	if(y==0)
	return 1;
	
	int temp=power(x,y/2);
	
	if(y%2==0)
	return temp*temp;
	else
	return x*temp*temp;
}
int main()
{
	int x,y;
	
	printf("Enter 'x' and 'y' :");
	scanf("%d %d",&x,&y);
	
	printf("%d\n",power(x,y));
	
	return 0;
}
