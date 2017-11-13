#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
	int val;
	struct list *next;
}List;

void insertAtBeg(List **head,int x)
{
	List *temp=malloc(sizeof(List));
	temp->val=x;
	temp->next=*head;
	*head=temp;
	return;
}

int hash(int x)
{
	return x%10;
}

int Search(List *head,int x)
{
	if(head==NULL)
	return 0;
	else
	while(head!=NULL && head->val!=x)
	head=head->next;
	
	if(head==NULL)
	return 0;
	else
	return 1;
	
}

void delElement(List **head,int x)
{
	List *cur=NULL;
	List *prev=NULL;
	
	if(*head==NULL)
	printf("List is Empty!\n");
	else
	{
		cur=*head;
		
		while(cur !=NULL && cur->val!=x)
		{
			prev=cur;
			cur=cur->next;
		}
		
		if(cur==NULL)
		printf("Element not found!\n");
		else if(prev==NULL)
		*head=cur->next;
		else
		prev->next=cur->next;
	}
}
void printList(List *temp)
{
	if(temp==NULL)
	printf("List is Empty!");
	else
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
	
	printf("\n");
	
}
void printHash(List *tab[])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d : ",i);
		printList(tab[i]);
	}
}
int main()
{
	List *tab[10];
	
	int x,i,ch;
	
	for(i=0;i<10;i++)
	tab[i]=NULL;
	
	printf("1.Insert\n,2.Print hash table\n3.Search\n4.Delete\n5.Exit\n\nEnter Choice: ");
	scanf("%d",&ch);
	
	while(ch!=5)
	{
		switch(ch)
		{
			case 1: printf("Enter element to insert: ");
				scanf("%d",&x);
				i=hash(x);
				insertAtBeg(&tab[i],x);
				break;
		
			case 2: printHash(tab);
				break;
		
			case 3: printf("Enter element to search: ");
				scanf("%d",&x);
				i=hash(x);
				if(Search(tab[i],x)==1)
				printf("Element exists hahsed at %d\n",i);
				break;
		
			case 4: printf("Enter element to delete: ");
				scanf("%d",&x);
				i=hash(x);
				delElement(&tab[i],x);
				break;
			
		}
	printf("1.Insert\n,2.Print hash table\n3.Search\n4.Delete\n5.Exit\n\nEnter Choice: ");
	scanf("%d",&ch);
	
	}
	
	return 0;

}
