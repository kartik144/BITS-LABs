#include<stdio.h>
#include<string.h>
int main()
{
	char s[100];
	fgets(s,100,stdin);
	
	int l=strlen(s)-1,i;
	int arr[l];
	
	for(i=0;i<l;i++)
	arr[i]=(int)(s[l-i]-48);
	
	int sum;
	
	for(i=1;i<l;i+=2)
	{
		arr[i]*=2;
		
		if(arr[i]>10)
		arr[i]=arr[i]/10+arr[i]%10;
	}
	
	for(i=0;i<l;i++)
	sum+=arr[i];
	
	if(sum%10==0)
	printf("Valid\n");
	else
	printf("Invalid\n");
	
	return 0;
}
