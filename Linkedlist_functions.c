#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*head=NULL;

void add_node_at_begin(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

void delete_note_from_beginning()
{
	struct node* temp;	
	temp=head;	
	if(head==NULL)
		printf("Empty List.");
	else
	{
		head=head->next;
		free(temp);
	}
}

void add_node_at_end(int data)
{
	struct node *temp,*temp1;	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	if(head==NULL)
	{
		head=temp;
		temp->next=NULL;
	}
	else
	{
		temp1=head;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		temp1->next=temp;
		temp->next=NULL;
	}
}

void delete_node_at_end()
{
	struct node *temp,*temp1;
	temp=head;	
	if(head==NULL)
		printf("Empty List.");
	else if(head->next==NULL)
	{
		free(head);
	}
	else
	{
		temp1=temp->next;		
		while(temp1->next!=NULL)
		{
			temp1=temp->next;
		}
	}
	free(temp1);
	temp->next=NULL;
}
void printList()
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
		printf("The list is empty.");
	else
	{
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	int i,d,n;
	printf("Enter how many nodes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("Enter data of node: ");
		scanf("%d",&d);
		add_node_at_end(d);		
	}
	
	printList();

	return 0;
}













