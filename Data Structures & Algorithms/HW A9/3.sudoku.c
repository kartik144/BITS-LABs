#include<stdio.h>
void refresh(int arr[])
{
	int i;
	for(i=0;i<9;i++)
	arr[i]=0;
	
	return;
}

void checkSudoku(int arr[9][9])
{
	int hash[9];
	refresh(hash);
	
	for(i=0;i<9;i++)
	{
		for()
	}
}

int main()
{
	int arr[9][9],i,j;
	
	for(i=0;i<9;i++)
	for(j=0;j<9;j++)
	scanf("%d",&arr[i][j]);
	
	checkSudoku(arr);
	
	return 0;
}
