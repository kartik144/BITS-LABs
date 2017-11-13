#include<stdio.h>
#include<stdlib.h>

typedef struct Link{
	int data;
	struct Link *next;
}Node;

void insertAtBeg(Node **head,int x)
{
	Node *node=malloc(sizeof(Node));
	node->next=*head;
	*head=node;
	node->data=x;
	return;
}

void insertAtEnd(Node **head,int x)
{
	Node *temp=malloc(sizeof(Node));
	temp->next=NULL;
	temp->data=x;
	
	if(*head==NULL)
	*head=temp;
	else
	{
		Node *n=*head;
		
		while(n->next!=NULL)
		n=n->next;
		
		n->next=temp;
	}
	
	return;
}

void printList(Node *head)
{
	if(head==NULL)
	printf("List is empty!\n");
	else
	{
		while(head->next!=NULL)
		{
			printf("%d->",head->data);
			head=head->next;
		}
		
		printf("%d->NULL\n",head->data);
	}
	
	return;
}

void reverseSubList(Node **head,int m,int l)
{
	Node *temp=*head;
	int len=0,i;
	
	while(temp!=NULL)
	{
		len++;
		temp=temp->next;
	}
	
	if(m+l-1>len)
	printf("reverse index and length out of bounds!\n");
	else
	{
		temp=*head;
		Node *prev=NULL;
		
		for(i=1;i<m;i++)
		{
			temp=temp->next;
			prev=temp;
		}
		
		Node *cur=temp->next;
		Node *nxt=NULL;
		Node *start=temp;
		Node *end;
		
		for(i=1;i<l;i++)
		{
			nxt=cur->next;
			cur->next=temp;
			temp=cur;
			cur=nxt;
			
			if(i==l-1)
			end=cur->next;
		}
		
		temp->next=end;
		prev->next=temp;
		
	}
}

int main()
{
	Node *head=NULL;
	
	insertAtEnd(&head,7);
	insertAtBeg(&head,6);
	insertAtBeg(&head,5);
	insertAtBeg(&head,4);
	insertAtBeg(&head,3);
	insertAtBeg(&head,2);
	insertAtBeg(&head,1);
	insertAtEnd(&head,8);
	
	printList(head);
	reverseSubList(&head,2,3);
	//printf("*");
	printList(head);
	
	return 0;
}
