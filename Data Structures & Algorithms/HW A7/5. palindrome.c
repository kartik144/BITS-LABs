#include<stdio.h>
#include<stdlib.h>
typedef struct LinkedList
{
	int data;
	struct LinkedList *next;
}List;

int getLength(List *temp)
{
	int c=0;
	
	while(temp!=NULL)
	{
		temp=temp->next;
		c++;
	}
	
	return c;
}

void insertAtBeg(List **head,int x)
{
	List *temp=malloc(sizeof(List));
	temp->data=x;
	temp->next=*head;
	*head=temp;
	return;
}

void isPalindrome(List *head)
{
	int l=getLength(head),i,k;
	int stack[l],top=-1;
	List *temp=head;
	
	for(i=1;i<=l/2;i++)
	{
		stack[++top]=temp->data;
		temp=temp->next;
	}
	
	if(l%2==0)
	k=l/2+1;
	else 
	{
		k=l/2+2;
		temp=temp->next;
	}
	
	//printf("%d %d ",l,k);
	
	for(i=k;i<=l;i++)
	{
		//printf("%d %d\n",stack[top],temp->data);
		
		if(stack[top]==temp->data)
		top--;
		
		temp=temp->next;
	}
	
	if(top!=-1)
	printf("Not ");
	
	printf("Palindrome\n");
	return;
}

int main()
{
	List *head=NULL;
	
	insertAtBeg(&head,1);
	insertAtBeg(&head,2);
	insertAtBeg(&head,3);
	//insertAtBeg(&head,3);
	insertAtBeg(&head,2);
	insertAtBeg(&head,8);
	
	isPalindrome(head);
	
	return 0;
}
