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

Node * reverseRecur(Node *cur,Node *pre)
{	
	if(cur==NULL)
	{
		return NULL;
	}
	if(cur->next==NULL)
	{
		cur->prev=NULL;
		cur->next=pre;
		printList(cur);
		return cur;
	}
	else
	{
		Node *t=cur->next;
		Node *pre=cur;
		cur->next=cur->prev;
		cur->prev=t;
		return reverseRecur(t,pre);
	}
	
}

void reverseIter(Node **head)
{
	if(*head==NULL)
	printf("List is Empty!\n");
	else
	{
		Node *temp=*head;
		Node *pre=NULL;
	
		while(temp->next!=NULL)
		{
			Node *t=temp->next;
			temp->next=temp->prev;
			temp->prev=t;
			pre=temp;
			temp=t;
		}
		
		temp->prev=NULL;
		temp->next=pre;
		*head=temp;
		
		printList(*head);
	}
	return;
}

int main()
{
	Node *head=NULL;
	int x,i;
	char ch='a';
	
	printf("a. Insert an element at the beginning\nb. Insert an element at the end\nc.Reverse iteratively\nd.Reverse recursive\ne.Exit\nEnter your choice: ");
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
					
			case 'c':	reverseIter(&head);
					break;
					
			case 'd':	head=reverseRecur(head,NULL);
					break;
					
			case 'e':	break;
		}
		
		printf("a. Insert an element at the beginning\nb. Insert an element at the end\nc.Reverse iteratively\nd.Reverse recursive\ne.Exit\nEnter your choice: ");
		scanf(" %c",&ch);
	}
	
	return 0;
}
