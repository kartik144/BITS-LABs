#include<stdio.h>

typedef struct in
{
	int a,b;
}In;

In stack[1000];
int top;

void push(In x)
{
	if(top<10000)
	stack[++top]=x;
	else
	printf("Overflow!\n");
	
	return;
}

void pop()
{
	if(top==-1)
	printf("Underflow!\n");
	else
	top--;
	
	return;
}

In peek()
{
	if(top==-1)
	{
		printf("Underflow! Returning -9999\n");
		In temp;
		temp.a=temp.b=-9999;
		return temp;
	}
	else
	{
		return stack[top];
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	
	top=-1;
	int i,c=0;
	
	In temp;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp.a);
		temp.b=1;
		
		while(top!=-1 && peek().a<=temp.a)
		{
			c+=peek().b;
			
			if(peek().a==temp.a)
			temp.b+=peek().b;
			
			pop();
		}
		
		if(top!=-1)
		c++;
		
		push(temp);
		
	}
	
	printf("%d\n",c);
	return 0;
}
