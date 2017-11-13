#include<stdio.h>
typedef struct cell
{
	int x,y;
}Cell;

int top=-1;
Cell stack[10000];

void push(Cell t)
{
	if(top==-9999)
	printf("Overflow!\n");
	else
	stack[++top]=t;
	return;
}

Cell pop()
{
	if(top==-1)
	{
		Cell t;
		t.x=-1,t.y=-1;
		printf("Underflow!\n");
		return t;
	}
	else
	return stack[top--];
}

Cell peek()
{
	if(top==-1)
	{
		Cell t;
		t.x=-1,t.y=-1;
		printf("Underflow!\n");
		return t;
	}
	else
	return stack[top];
}

void printStack()
{
	while(top!=-1)
	{
		printf("%d %d\n",peek().x,peek().y);
		pop();
	}
	
	//printf()
	return;
}

int main()
{
	int n,i,j;
	scanf("%d",&n);
	
	int arr[n][n];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	scanf("%d",&arr[i][j]);
	
	arr[0][0]=2;
	Cell temp,p;
	temp.x=temp.y=0;
	
	while(!(temp.x==n-1 && temp.y==n-1) && arr[temp.x][temp.y]!=3)
	{
		if(arr[temp.x][temp.y+1]==1 && temp.y<n)
		{
			push(temp);
			temp.y++;
			arr[temp.x][temp.y]++;
		}
		else if(arr[temp.x+1][temp.y]==1 && temp.x<n)
		{
			push(temp);
			temp.x++;
			arr[temp.x][temp.y]++;
		}
		else if(arr[temp.x][temp.y-1]==1 && temp.y<n)
		{
			push(temp);
			temp.y--;
			arr[temp.x][temp.y]++;
		}
		else if(arr[temp.x-1][temp.y]==1 && temp.y<n)
		{
			push(temp);
			temp.x--;
			arr[temp.x][temp.y]++;
		}
		else if(arr[0][0]==3)
		{
			printf("No way!\n");
			return 0;
		}
		else
		{
			arr[temp.x][temp.y]=3;
			p=pop();
			temp=p;
		}
	}
	
	printStack();
	return 0;
}
