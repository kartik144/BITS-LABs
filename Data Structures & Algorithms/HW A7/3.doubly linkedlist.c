#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
	struct LinkedList *prev;
}Node;

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

int getLength(Node *temp)
{
	int c=0;
	
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	
	return c;
}

void insertAtBeg(Node **head,int x)
{
	Node *H=*head;
	Node *temp=malloc(sizeof(Node));
	temp->next=*head;
	temp->prev=NULL;
	
	if(H!=NULL)
	H->prev=temp;
	
	temp->data=x;
	*head=temp;
	printList(*head);
	return;
}

void insertAtEnd(Node **head,int x)
{
	if(*head==NULL)
	insertAtBeg(&(*head),x);
	else
	{
		Node *temp=*head;
		Node *new=malloc(sizeof(Node));
		new->data=x;
		new->next=NULL;
		
		while(temp->next!=NULL)
			temp=temp->next;
			
		temp->next=new;
		new->prev=temp;
		
		printList(*head);
	}
	
	return;
	
}

void insertAtIndex(Node **head,int x,int i)
{
	int l=getLength(*head);
	
	if(i==0)
	insertAtBeg(&(*head),x);
	else if(i==l)
	insertAtEnd(&(*head),x);
	else if(i<l)
	{
		Node *temp=*head;
		Node *pre=NULL;
		Node *new=malloc(sizeof(Node));
		new->data=x;
		
		int n=0,j;
		
		for(j=1;j<=i;j++)
		{
			pre=temp;
			temp=temp->next;
		}
		
		new->prev=temp->prev;
		temp->prev=new;
		new->next=temp;
		pre->next=new;
		
		printList(*head);
		
	}
	else
	printf("Given index is out of bounds!\n");
	
	return;
}

int main()
{
	Node *head=NULL;
	int x,i;
	char ch='a';
	
	printf("a. Insert an element at the beginning\nb. Insert an element at the end\nc. Insert an element after an index (input i - index)\nd. Print the elements of the list\ne.Exit\nEnter your choice: ");
	scanf(" %c",&ch);
	
	while(ch!='e')
	{
		switch(ch)
		{
			case 'a':	printf("Enter element to be inserted: ");
					scanf("%d",&x);
					insertAtBeg(&head,x);
					break;
					
			case 'b':	printf("Enter element to be inserted: ");
					scanf("%d",&x);
					insertAtEnd(&head,x);
					break;
					
			case 'c':	printf("Enter element to be inserted and its index: ");
					scanf("%d %d",&x,&i);
					insertAtIndex(&head,x,i);
					break;
					
			case 'd':	printList(head);
					break;
					
			case 'e':	break;
		}
		
		printf("a. Insert an element at the beginning\nb. Insert an element at the end\nc. Insert an element after an index (input i - index)\nd. Print the elements of the list\ne.Exit\nEnter your choice: ");
		scanf(" %c",&ch);
	}
	
	return 0;
}
