#include<stdio.h>

int ispossible(int arr[],int m,int n,int mid)
{
	int d=0,i=0;
	
	for(i=0;i<n;i++)
	if(arr[i]<mid)
	d+=arr[i];
	else
	d+=mid;
	
	if(d>=mid*m)
	return 1;
	else
	return 0;
	
}

int getTeams(int arr[],int n,int m)
{
	int l=0,d=0,h,i,mid;
	
	for(i=0;i<n;i++)
	{
		d+=arr[i];
	}
	
	h=d/m;
	//printf("%d %d\n",l,h);
	while(h-l>1)
	{
		mid=l+(h-l)/2;
		//printf("*%d %d %d\n",l,mid,h);
		if(ispossible(arr,m,n,mid)==1)
		l=mid;
		else
		h=mid;
	}
	
	if(ispossible(arr,m,n,h)==1)
	l=h;
	
	return l;
}

int main()
{
	int n,m,i;
	scanf("%d %d",&n,&m);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	int t=getTeams(arr,n,m);
	printf("%d\n",t);
	
	return 0;
}
