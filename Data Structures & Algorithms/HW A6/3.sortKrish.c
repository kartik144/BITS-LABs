#include<stdio.h>
#include<string.h>
int numberOfOnes(int n)
{
	int sum=0;
	
	while(n!=0)
	{
		sum+=n%2;
		n=n/2;
	}
	
	return sum;
}

void getValues(char name[][50],int arr[],int n)
{	
	int i,j;
	
	for(i=0;i<n;i++)
	{
		int ascii=0;
		
		for(j=0;j<strlen(name[i]);j++)
		ascii+=(int)name[i][j];
		
		arr[i]=numberOfOnes(ascii);
	}
}

void merge(char name[][50],int arr[],int l,int m,int r)
{
	int n1,n2;
	n1=m-l+1;
	n2=r-m;
	
	int i,j,k;
	int L[n1],R[n2];
	char nL[n1][50],nR[n2][50];
	
	for(i=0;i<n1;i++)
	{
		L[i]=arr[i+l];
		strcpy(nL[i],name[i+l]);
	}
	
	for(j=0;i=j<n2;j++)
	{
		R[j]=arr[m+1+j];
		strcpy(nR[j],name[m+1+j]);
	}
	
	i=0,j=0,k=l;
	
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			strcpy(name[k],nL[i]);
			i++;
		}
		else
		{
			arr[k]=R[j];
			strcpy(name[k],nR[j]);
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		arr[k]=L[i];
		strcpy(name[k],nL[i]);
		k++;
		i++;
	}
	
	while(j<n2)
	{
		arr[k]=R[j];
		strcpy(name[k],nR[j]);
		k++;
		j++;
	}
}
void mergeSort(char name[][50],int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		
		mergeSort(name,arr,l,m);
		mergeSort(name,arr,m+1,r);
		
		merge(name,arr,l,m,r);
	}
}

void countSort(char name[][50],int arr[],int n)
{
	int i,j;
	int a[20],b[n];
	char s[n][50];
	
	for(i=0;i<20;i++)
	a[i]=0;
	
	for(i=0;i<n;i++)
	a[arr[i]]++;
	
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	printf("\n");
	
	for(i=1;i<20;i++)
	printf("%d ",a[i]);
	printf("\n");
	
	for(i=1;i<20;i++)
	a[i]=a[i]+a[i-1];
	
	for(i=1;i<20;i++)
	printf("%d ",a[i]);
	
	printf("\n");
	
	for(j=n-1;j>=0;j--)
	{
		b[a[arr[j]]]=arr[j];
		strcpy(s[a[arr[j]]-1],name[j]);
		a[arr[j]]--;
	}
	
	for(i=0;i<n;i++)
	printf("%s \n",s[i]);
	
	return;
}



int main()
{
	printf("Enter the number of names: ");
	int n,i;
	scanf("%d",&n);
	
	int arr[n];
	char name[n][50];
	
	printf("Enter the names\n");
	
	for(i=0;i<n;i++)
	scanf("%s",name[i]);
	
	getValues(name,arr,n);
	
	for(i=0;i<n;i++)
	printf ("%s %d\n",name[i],arr[i]);
	
	/*mergeSort(name,arr,0,n-1);
	for(i=0;i<n;i++)
	printf ("%s %d\n",name[i],arr[i]);*/
	
	countSort(name,arr,n);
	
	/*for(i=0;i<n;i++)
	printf ("%s %d\n",name[i],arr[i]);*/

	printf("\n");

	return 0;
}
