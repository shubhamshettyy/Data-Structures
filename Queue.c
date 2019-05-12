
/*
Name: Shubham Shetty 
Batch: D4 FE COMPS
Roll No: 50


Aim : To explore the concept of application of Queue as linear data structure
Question :  Consider a single queueing system for a food joint. There is a single queue of customers.
The customers however, are served by three different counters. The moment a counter is
free, the first customer in the queue is serviced at the counter. It is possible that at a
particular time instant only 2 counters are free to serve customers, so at that point the first
2 customers are removed from the queue for servicing. Simulate this system’s behavior.
Your program must:
i. Create a queue for n customers
ii. At every instant of time ask for how many counters are free(k) and then remove
k customers from the queue accordingly. (Do this till all n customers are serviced.
Assume: There are no new customers adding to the queue.)
iii. Display the queue contents at each instant after removing customer

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int customer;
    struct node *next;
}node;        //INITIALIZING THE STRUCTURE//

void joinQueue(int,int*,node **,node **);
void display(node **);
void deQueue(node **,int*);

void main()
{       node *rear, *front;
        int nodeCount=0;
        int n,i,quit=0,counters;
        int invalid;
        printf("How many customers?\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {

                joinQueue((i+1),&nodeCount,&front,&rear);
        }
        display(&front);
        while(!quit)
        {       invalid=1;
                printf("Enter 1 to quit and 0 to continue\n");
                scanf("%d",&quit);
                if(quit!=1)
                {

                       while(invalid)
                       {       printf("How many counters are free?\n");
                               scanf("%d",&counters);
                                 if(counters>3)
                                {
                                        printf("Invalid input!There are only 3 counters!\n");
                                        invalid=1;
                                }
                                 else
                                 {
                                      invalid =0;

                                 for(i=0;i<counters;i++)
                                 {
                                          if(nodeCount==0)
                                        {
                                         printf("Queue is already empty!\n");//QUE IS EMPTY//
                                         break;
                                         }
                                        deQueue(&front,&nodeCount);
                                 }
                                 }
                        }
                if(nodeCount!=0)
                {       display(&front);}
                }

        }
}
void joinQueue(int c,int *nodeCount,node **front,node**rear)
{
        node *current = (node*)malloc(sizeof(node));
        if(current == NULL)//if memory could not be allotted
    {
        printf("Unable to allocate node\n");
        return;
    }
    current->customer=c;
    current->next=NULL;
    if(*nodeCount==0)//if the node is the first node
         {
                *front=current;//head and tail are both the current node as list has only one element
                *rear=current;
         }
    else
        {
                (*rear)->next = current;//previous tail now points to current node
                *rear = current;//current node now becomes the new tail
        }
    (*nodeCount)++;
}
void deQueue(node **front,int *nodeCount)
{
        node *current=*front;
        printf("customer %d is served\n",current->customer);
        *front=current->next;
        free(current);
        (*nodeCount)--;

}
void display(node **front)//DISPLAY FUNCTION//
{
        node* current=*front;
        printf("Queue from front:\n");
        while(current!=NULL)
        {
                printf("%d\n",current->customer);
                current=current->next;
        }
}


/*OUTPUT

How many customers?
10
Queue from front:
1
2
3
4
5
6
7
8
9
10
Enter 1 to quit and 0 to continue
0
How many counters are free?
3
customer 1 is served
customer 2 is served
customer 3 is served
Queue from front:
4
5
6
7
8
9
10
Enter 1 to quit and 0 to continue
0
How many counters are free?
2
customer 4 is served
customer 5 is served
Queue from front:
6
7
8
9
10
Enter 1 to quit and 0 to continue
0
How many counters are free?
5
Invalid input!There are only 3 counters!
How many counters are free?
3
customer 6 is served
customer 7 is served
customer 8 is served
Queue from front:
9
10
Enter 1 to quit and 0 to continue
0
How many counters are free?
1
customer 9 is served
Queue from front:
10
Enter 1 to quit and 0 to continue
0
How many counters are free?
3
customer 10 is served
Queue is already empty!
Enter 1 to quit and 0 to continue
0
How many counters are free?
1
Queue is already empty!
Enter 1 to quit and 0 to continue
1


Conclusion:
We learnt how to use queue data structure. We learnt queue operstions such as enqueue and dequeue.

*/
