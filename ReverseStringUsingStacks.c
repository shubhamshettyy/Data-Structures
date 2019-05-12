#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st{
	char data;
	struct st* next;

};

struct st *top=NULL;
char push(char data)
{
	struct st *temp;
	temp=(struct st*)malloc(sizeof(struct st));
	temp->data=data;
	if(top==NULL)
	{
		top=temp;
		top->next=NULL;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}

char reverse()
{
	struct st *temp;
	char data;
	temp=top;
	if(top==NULL)
		printf("Empty stack.");
	else
	{
		data=top->data;
		top=top->next;
		free(temp);
		return data;
	}
}
int main()
{
	int i,n;
	char str[20];
	printf("Enter a string: ");
	scanf("%s",str);
	// printf("abc");
	n=strlen(str);
	for(i=0;i<n;i++)
	{
		push(str[i]);
	}
	printf("Before reversing\n");
	for(i=0;i<n;i++)
		printf("%c",str[i]);

	printf("\n");
	for(i=0;i<n;i++)
	{
		str[i]=reverse();
	}
	printf("After reversing\n");
	for(i=0;i<n;i++)
		printf("%c",str[i]);

}

