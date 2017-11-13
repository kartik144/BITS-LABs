#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList{
	int data;
	struct LinkedList *next;
}Node;

void insertAtBeg(Node **head,int x)
{
	Node *node=malloc(sizeof(Node));
	node->data=x;
	node->next=*head;
	*head=node;
	return;
}

void reverse(Node **head)
{
	Node *curr=*head;
	Node *prev=NULL;
	Node *temp=NULL;
	
	while(curr!=NULL)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	
	*head=prev;
	
}

void printList(Node *node)
{
	if(node==NULL)
	{
		printf("List is empty!\n");
		return;
	}
	else
	{
		while(node->next!=NULL)
		{
			printf("%d->",node->data);
			node=node->next;
		}
		
		printf("%d->NULL\n",node->data);
		return;
	}
}

int main()
{
	int x;
	char ch='Y';
	Node *head=NULL;
	
	while(ch=='Y' || ch=='y')
	{
		printf("Enter value of the node: ");
		scanf(" %d",&x);
		insertAtBeg(&head,x);
		printf("Do you wish to add another node(Y/n)? ");
		scanf(" %c",&ch);
	}
	
	printf("Linked list: ");
	printList(head);
	
	reverse(&head);
	
	printf("Reversed List: ");
	printList(head);
	
	return 0;
}
