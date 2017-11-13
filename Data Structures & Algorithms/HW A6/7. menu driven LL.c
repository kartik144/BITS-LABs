#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
	int data;
	struct LinkedList * next;
} Node;

void insertAtBeg(Node **head,int x)
{
	Node * node=malloc(sizeof(Node));
	node->data=x;
	node->next=*head;
	*head=node;
	
	printf("Data successfully entered at the beginning!\n");
} 

void insertAtEnd(Node **head,int x)
{
	Node *node=malloc(sizeof(Node));
	node->data=x;
	node->next=NULL;
	if(*head==NULL)
	*head=node;
	else
	{
		Node *temp=*head;
	
		while(temp->next!=NULL)
		temp=temp->next;
	
		temp->next=node;
	}
	printf("Data successfully entered at the end!\n");
}

void insertInMiddle(Node *head,int x,int y)
{
	Node *node=malloc(sizeof(Node));
	node->data=x;
	Node *temp=head;
	
	while(temp->data!=y)
	temp=temp->next;
	
	if(temp==NULL)
	printf("%d Not Found",y);
	else
	{
		node->next=temp->next;
		temp->next=node;
	}	
	
	printf("Data successfully entered after %d!\n",y);
}

void printList(Node *node)
{
	while(node!=NULL)
	{
		printf("%d ",node->data);
		node=node->next;
	}
}

int main()
{
	Node * head=NULL;
	printf("Enter your choice?\n1.Insert at beginning.\n2.Insert at end\n3.Insert atfter a number\n4.Exit\n");
	int choice,x,y;
	scanf("%d",&choice);
	
	while(choice!=4)
	{
		switch(choice)
		{
			case 1: printf("Enter the data ");
				scanf("%d",&x);
				insertAtBeg(&head,x);
				break;
				
			case 2:	printf("Enter the data ");
				scanf("%d",&x);
				insertAtEnd(&head,x);
				break;
				
			case 3: printf("Enter the data ");
				scanf("%d",&x);
				printf("Enter the value after which data is to be inserted");
				scanf("%d",&y);
				insertInMiddle(head,x,y);
				break;
			case 4: break;
		}
		
		printf("Enter your choice?\n1.Insert at beginning.\n2.Insert at end\n3.Insert atfter a number\n4.Exit\n");
		scanf("%d",&choice);
	}
	
	printList(head);
} 
