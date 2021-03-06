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

Node * reverse(Node *curr,Node* next,Node *prev)
{
	if(next==NULL)
	{
		curr->next=prev;
		return curr;
	}
	else
	{
		Node *temp=next;
		next=next->next;
		curr->next=prev;
		prev=curr;
		return reverse(temp,next,prev);
	}
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
	
	head=reverse(head,head->next,NULL);
	
	printf("Reversed List: ");
	printList(head);
	
	return 0;
}
