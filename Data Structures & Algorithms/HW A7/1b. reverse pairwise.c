#include<stdio.h>
#include<stdlib.h>

typedef struct Link{
	int data;
	struct Link *next;
}Node;

void insertAtBeg(Node **head,int x)
{
	Node *temp=malloc(sizeof(Node));
	temp->next=*head;
	*head=temp;
	temp->data=x;
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

void reversePairs(Node **head)
{
	Node *temp=*head;
	
	if(temp->next==NULL)
	return;
	else
	{
		Node *temp2=temp->next;
		Node *prev=NULL;
		
		while(temp!=NULL && temp2!=NULL)
		{
			/*if(prev!=NULL)
			printf(" %d %d %d\n",prev->data,temp->data,temp2->data);*/
			
			if(prev==NULL)
			*head=temp2;
			else
			prev->next=temp2;
			
			temp->next=temp2->next;
			temp2->next=temp;
			
			prev=temp;
			
			//if(temp->next!=NULL)
			temp=temp->next;
			
			//else
			//temp=NULL;
				
			if(temp!=NULL)
			temp2=temp->next;
			//printList(*head);
		}
	}
}

int main()
{
	Node *head=NULL;
	
	insertAtBeg(&head,7);
	insertAtBeg(&head,6);
	insertAtBeg(&head,5);
	insertAtBeg(&head,4);
	insertAtBeg(&head,3);
	insertAtBeg(&head,2);
	insertAtBeg(&head,1);
	
	printList(head);
	reversePairs(&head);
	//printf("*");
	printList(head);
	
	return 0;
}
