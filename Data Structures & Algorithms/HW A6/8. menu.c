#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
	int data;
	struct LinkedList * next;
} Node;

void printList(Node *node)
{
	if(node==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	
	while(node->next!=NULL)
	{
		printf("%d->",node->data);
		node=node->next;
	}
	
	printf("%d\n",node->data);
}

void insertAtBeg(Node **head,int x)
{
	Node *node=malloc(sizeof(Node));
	node->data=x;
	node->next=*head;
	*head=node;
	
	 printList(*head);
}

void delBeg(Node **head)
{
	if(*head!=NULL)
	{
		Node *temp=*head;
		*head=temp->next;
		free(temp);
		printList(*head);
	}
	else
	printf("List is Empty,cannot delete!\n");
	
}

void delEnd(Node **head)
{
	if(*head!=NULL)
	{
		Node* temp=*head;
		if(temp->next==NULL)
		*head=NULL;
		else
		{
			Node *prev=NULL;
			while(temp->next!=NULL)
			{
				prev=temp;
				temp=temp->next;
			}
			
			prev->next=NULL;
		}
		
		free(temp);
		printList(*head);
	}
	else
	printf("List is Empty,cannot delete!\n");
}

int main()
{
	Node * head=NULL;
	printf("Enter your choice?\na.Insert at beginning.\nb.Delete from beginning\nc.Delete from end\nd.Exit\n");
	int x;
	char choice;
	scanf("%c",&choice);
	
	while(choice!='d')
	{
		switch(choice)
		{
			case 'a':printf("Enter the data ");
				scanf("%d",&x);
				insertAtBeg(&head,x);
				break;
				
			case 'b':delBeg(&head);
				break;
				
			case 'c':delEnd(&head);
				break;
				
			case 'd': break;
		}
		
		printf("Enter your choice?\na.Insert at beginning.\nb.Delete from beginning\nc.Delete from end\nd.Exit\n");
		scanf("%c",&choice);
	}
	
	//printList(head);
} 
