#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char val;
	struct node *left,*right;
}Node;

Node * createNode(char ch)
{
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->val=ch;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

int isOperator(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
		case '*':
		case '/':return 1;
	}
	
	return 0;
}

void inorderWalk(Node *node)
{
	if(node->left!=NULL)
	inorderWalk(node->left);
	
	printf("%c",node->val);
	
	if(node->right!=NULL)
	inorderWalk(node->right);
}

int main()
{
	char s[100];
	scanf("%s",s);
	int i,top=-1,l=strlen(s);
	
	//Node *arr[l];
	Node *stack[l];
	
	//for(i=0;i<l;i++)
	//arr[i]=createNode(s[i]);
	
	for(i=0;i<l;i++)
	{
		Node *temp=createNode(s[i]);
		
		if(isOperator(temp->val))
		{
			temp->right=stack[top--];
			temp->left=stack[top--];
			stack[++top]=temp;
		}
		else
		stack[++top]=temp;
	}
	
	inorderWalk(stack[top]);
	printf("\n");
	return 0;
}
