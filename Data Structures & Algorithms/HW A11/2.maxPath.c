#include<stdio.h>
typedef struct node
{
	int data;
	struct node *l,*r;
}Node;

Node * create(int x)
{
	Node *temp=malloc(sizeof(Node));
	temp->l=NULL;
	temp->r=NULL;
	temp->data=x;
	return temp;
}

void printPath(Node *temp)
{
	if(temp->l==NULL && temp->r==NULL)
	printf("%d",temp->data);
	
	printf
}
int main()
{
	
}
