#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
	int data;
	struct LinkedList * next;
}Node;

void insertAtBeg(Node **head,int x)
{
	Node *node=malloc(sizeof(Node));
	node->data=x;
	node->next=*head;
	*head=node;
}

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
	
	printf("%d->NULL\n",node->data);
	return;
}

Node * mergeSortedList(Node *list1,Node *list2)
{
	Node *head=NULL;
	Node *tail=NULL;
	while(list1!=NULL && list2!=NULL)
	{
		if(list1->data < list2->data)
		{
			if(head==NULL)
			{
				head=list1;
				list1=list1->next;
				//head->next=NULL;
				tail=head;
			}
			else
			{	
				tail->next=list1;
				list1=list1->next;
				tail=tail->next;
				tail->next=NULL;
			}
				
		}
		else
		{
			if(head==NULL)
			{
				head=list2;
				list2=list2->next;
				//head->next=NULL;
				tail=head;
			}
			else
			{	
				tail->next=list2;
				list2=list2->next;
				tail=tail->next;
				tail->next=NULL;
			}
		}
	}
	//printf("\n*");
	if(list1==NULL)
	{
		if(head==NULL)
		head=list2;
		else
		tail->next=list2;
	}
	
	
	if(list2==NULL)
	{
		if(head==NULL)
		head=list1;
		else
		tail->next=list1;
	}
	//printf("=*");
	return head;
}

int main()
{
	printf("Enter the first List\n");
	int x;
	Node *head1=NULL;
	
	int ch=1;
	while(ch)
	{
		scanf("%d",&x);
		insertAtBeg(&head1,x);
		printf("Press 1 to add another node,0 to end list1 ");
		scanf("%d",&ch);
	}
	
	printf("List 1: ");
	printList(head1);
	
	Node *head2=NULL;
	printf("Enter the second List\n");
	ch=1;
	while(ch)
	{
		scanf("%d",&x);
		insertAtBeg(&head2,x);
		printf("Press 1 to add another node,0 to end list1 ");
		scanf("%d",&ch);
	}
	
	printf("List 2: ");
	printList(head2);
	
	Node *head=mergeSortedList(head1,head2);
	printf("\nMerged List:");
	printList(head);
}
