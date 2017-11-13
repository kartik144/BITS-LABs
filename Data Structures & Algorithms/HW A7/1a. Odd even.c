#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList
{
	 int data;
	 struct LinkedList *next;
}Node;

void insertAtBeg(Node **head,int x)
{
	Node * temp=malloc(sizeof(Node));
	temp->data=x;
	temp->next=*head;
	*head=temp;
	
	return;
}

void printList(Node *temp)
{
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	
	printf("%d->NULL\n",temp->data);
	return;
}

void evenBeforeOdd(Node **head)
{
	Node *curr=*head;
	Node *prev=NULL;
	Node *prev1=NULL;
	
	while(curr!=NULL)
	{	
		Node *in=*head;
		int flag=1;
	
		if(curr->data%2==0)
		{
			Node *prev=NULL;
			
			while(in!=NULL && flag)
			{
				if(in->data%2==1)
				{
					if(prev==NULL)
					*head=curr;
					else
					prev->next=curr;
					
					prev1->next=curr->next;
					curr->next=in;	
					
					flag=0;
				
				}
				prev=in;
				in=in->next;
				
			}
		}
		
		printList(*head);
		prev1=curr;
		curr=curr->next;
	}
}

int main()
{
	Node *head=NULL;
	
	insertAtBeg(&head,6);
	insertAtBeg(&head,5);
	insertAtBeg(&head,4);
	insertAtBeg(&head,3);
	insertAtBeg(&head,2);
	insertAtBeg(&head,1);
	
	printList(head);
	evenBeforeOdd(&head);
	//printf("*");
	printList(head);
	
	return 0;
}
