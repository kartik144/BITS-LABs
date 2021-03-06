#include<stdio.h>
#include<string.h>
char stack[10000];
int top=-1;
int st[10000];
void push(char x)
{
	if(top==9999)
	printf("Overflow!\n");
	else
	stack[++top]=x;
	
	return;
}

char pop()
{
	if(top==-1)
	{
		printf("Underflow!\n");
		return '\0';
	}
	else
	{
		char ch=stack[top];
		top--;
		return ch;
	}
}

char peek()
{
	if(top==-1)
	{
		printf("Underflow!\n");
		return '\0';
	}
	else
	return stack[top];
}

void reverse(char s[])
{
	int l=strlen(s),i,k;
	
	for(i=0,k=l-1;i<=(l-1)/2;i++,k--)
	{
		char ch=s[i];
		s[i]=s[k];
		s[k]=ch;
	}
}

int isOperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')': return 1;
	}
	
	return 0;
}

int getPrecedance(char ch)
{
	switch(ch)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
	return 0;
}

int pushOperators(char ch,char r[],char p)
{	
	int p1=getPrecedance(peek());
	int p2=getPrecedance(ch);
	
	if(p2>p1)
	push(ch);
	else if(p2==p1)
	{
		r[p++]=pop();
		push(ch);
	}
	else if(top>=0)
	{
		r[p++]=pop();
		pushOperators(ch,r,p);
	}
	
	return p;
				
}

void infixToPostfix(char s[],char r[])
{
	
	int i,l=strlen(s),p=0;

	for(i=0;i<l;i++)
	{
		char ch=s[i];
		
		if(isOperator(ch)==0)
		r[p++]=ch;
		else
		{
			if(top==-1 || peek()=='(')
			push(ch);
			else if(ch=='(')
			push(ch);
			else if(ch==')')
			{
				while(peek()!='(')
				r[p++]=pop();
				pop();
			}
			else
			p=pushOperators(ch,r,p);
		}
	}
	//printf("%c\n",peek());
	while(top>=0)
	r[p++]=pop();
	
	r[p]='\0';
	
	return;
}

int evaluate(char r[])
{
	top=-1;
	int i,l=strlen(r);
	
	for(i=0;i<l;i++)
	{
		char ch=r[i];
		
		if(isOperator(ch)==0)
		{
			st[++top]=(int)ch-48;
			//printf("*%d\n",st[top]);
		}
		else
		{
			int n1=st[top--];
			int n2=st[top--];
			int t;
			
			switch(ch)
			{
				case '+': t=n1+n2;
					  break;
				case '-': t=n2-n1;
					  break;
				case '*': t=n1*n2;
					  break;
				case '/': t=n2/n1;
					  break;
			}
			
			st[++top]=t;
		}
		
	}
	
	return st[top];
}

int main()
{	
	char s[10000],r[10000];
	scanf("%s",s);
	infixToPostfix(s,r);
	printf("%s\n",r);
	int res=evaluate(r);
	printf("%d\n",res);
	
	return 0;
}
