#include<stdio.h>
int slen(char *s1)
{
	int i=0;
	
	while(s1[i]!='\0')
	{
		i++;
	}
	
	return i;
}

int scmp(char *s1,char *s2)
{
	int l1=slen(s1),l2=slen(s2);
	int i,flag=0;
	int l=(l1>l2)?l2:l1;
	
	for(i=0;i<l;i++)
	if(s1[i]!=s2[i])
	{
		if(s1[i]>s2[i])
		flag=1;
		else
		flag=-1;
		
		break;
	}
	
	return flag;
	
}

int binsearch(int i,int j,char s[][100],char *key)
{
	int mid;
	int n=j;
	printf("%d %d\n",i,j);
	mid=(i+j)/2;
	int level = scmp(s[mid],key);
	if(i==j)
	{
		if(level == 0)
		{
		return 1;
		}
		else
		return 0;
	}
	if(i<j)
	{	
		
		if(level==0)
			return 1+binsearch(i,mid-1,s,key)+binsearch(mid+1,j,s,key);
		
		else if (level==1)
			return binsearch(i,mid-1,s,key);
		
		else if(level==-1)
			return binsearch(mid+1,j,s,key);
		
	}
	
	return 0;
}

int main()
{
	int n,i,j,count=0;
	scanf("%d",&n);
	char buff[50];
	fgets(buff,50,stdin);
	
	char s[n][100];
	
	for(i=0;i<n;i++)
	{
		fgets(s[i],100,stdin);
	}
	
	char key[100];
	fgets(key,100,stdin);
	
	count=binsearch(0,n-1,s,key);
	
	printf("%d\n",count);	
	
	return 0;
}
