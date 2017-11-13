#include<stdio.h>
char stack[1000];
int top=-1;

void push(char x)
{
	if(top==999)
	printf("Overflow!cannot Push!\n");
	else
	stack[++top]=x;
	
	return;
}

void pop()
{
	if(top==-1)
	printf("Underflow!Cannot Pop!\n");
	else
	top--;
	
	return;
}

char peek()
{
	if(top==-1)
	{
		printf("Underflow! Returning NULL!\n");
		return '\0';
	}
	else
	{
		return stack[top];
	}
}

int main()
{
	char s[1000];
	scanf("%s",s);
	
	int i=0,n=0,m=0,c=0;
	
	while(s[i]!='\0')
	{
		if(s[i]=='(')
		push(s[i]);
		else if(s[i]==')')
		{
			if(peek()=='(')
			pop();
			else
			push(s[i]);
		}
		i++;
	}
	
	while(top!=-1)
	{
		if(peek()=='(')
		n++;
		else
		m++;
		
		pop();
	}
	
	if(n%2==1)
	c+=(n+1)/2;
	else
	c+=n/2;
	
	if(m%2==1)
	c+=(m+1)/2;
	else
	c+=m/2;
	
	printf("%d\n",c);
	
	return 0;
}
