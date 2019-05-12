/*Name: Shubham  Shetty
Roll no: 50
UID: 2018130050
Batch: D4 FE COMPS


Problem statement: 
Evaluation of a postfix expression. Program is terminated by #.

*/

#include<stdio.h>
#include<ctype.h>
#define maxsize 10
struct st		//defining structure
{
	int s[maxsize];
	int top;
};

struct st mystack;
void create_stack()		//function to create stack
{
	mystack.top=-1;	//initializing top to -1
}

int push(int d)	//function to push into stack
{
	if(mystack.top==maxsize-1)
	{
		printf("Stack full");
		return -1;
	}
	else
	{
		mystack.top+=1;
		mystack.s[mystack.top]=d;	//add data to stack
	}
	//printf("%d",mystack.s[mystack.top]);
}
int pop()
{
	int t;
	t=mystack.s[mystack.top];
	mystack.top=(mystack.top)-1;
	return t;	//return element pointed by top
	
}

int main()
{
	create_stack();		//function call
	int ans;
	char s[10];
	int i=0;
	printf("Enter the expression: ");	//postfix expression 
	scanf("%s",s);
	while(s[i]!='#')
	{
		if(isdigit(s[i]))
		{
			push(s[i] - '0');	//typecasting into int
		}
		else
		{
			
			switch(s[i])
			{
				case '*':mystack.s[(mystack.top)-1]=mystack.s[mystack.top]*mystack.s[(mystack.top)-1];
					mystack.top-=1;
					break;	
				case '+':mystack.s[(mystack.top)-1]=mystack.s[mystack.top]+mystack.s[(mystack.top)-1];
					mystack.top-=1;
					break;	
				case '-':mystack.s[(mystack.top)-1]=mystack.s[mystack.top-1]-mystack.s[(mystack.top)];
					mystack.top-=1;
					break;	
				case '/':mystack.s[(mystack.top)-1]=mystack.s[mystack.top-1]/mystack.s[(mystack.top)];
					mystack.top-=1;
					break;						
			}
		}
		i++;
	}
	ans=pop();	//calling pop function
	printf("Postfix evaluation: %d\n",ans);
}

/*
Output:
Enter the expression: 345+/#
Postfix evaluation: 3

Enter the expression: 23456+-/*#
Postfix evaluation: 4

*/
