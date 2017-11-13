#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList{
	int data;
	struct LinkedList *next;
}List;

void insertAtBeg(List **head,int x)
{
	List *temp=malloc(sizeof(List));
	temp->data=x;
	temp->next=*head;
	*head=temp;
	return;
}

void generateList(List **head,int n)
{
	int i;
	
	for(i=n;i>=1;i--)
	insertAtBeg(&(*head),i);
	
	List *temp=*head;
	
	while(temp->next!=NULL)
	temp=temp->next;
	temp->next=*head;
	
	return;
}
void printList(List *temp)
{
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	
	printf("%d->NULL\n",temp->data);
	return;
}

void getResult(List **head,int k)
{
	List *temp=*head;
	List *prev=NULL;
	int i;
	
	for(i=1;i<k;i++)
	{
		prev=temp;
		temp=temp->next;
	}
	
	//printf("%d %d\n",temp->data,prev->data);
	
	*head=temp->next;
	
	prev->next=temp->next;
	free(temp);
	
	if((*head)->next==*head)
	{
		printf("%d\n",(*head)->data);
		return;
	}
	else
	return getResult(&(*head),k);
	
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	
	List *head=NULL;
	generateList(&head,n);
	
	//printf("%d\n",head->data);
	getResult(&head,k);
	
	return 0;
}
