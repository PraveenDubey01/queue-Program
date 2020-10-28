#include<stdio.h>
#include<process.h>
#define MAX 5

typedef int item_type;

typedef struct
{
	item_type e[MAX];
	int f,r;
}queue;

void init(queue* qp);
void insert(queue* qp,item_type item);
item_type delete(queue* qp);
item_type peek(queue* qp);
int size(queue*qp);
void display(queue*qp);
int isempty(queue*qp);
int isfull(queue*qp);
void display(queue*qp);

void init(queue* qp)
{
	qp->f = 0;
	qp->r = -1;
}
int isempty(queue* qp)
{
	return qp->f==qp->r+1;
}

int isfull(queue*qp)
{
	return qp->r==MAX-1;
}

void insert(queue* qp,item_type item)
{
	int i;
	if(isfull(qp))
	{
		if(qp->f==0)
		{
		   puts("Queue is full!");
		   return;
	    }
	    for(i=0;i<qp->r-qp->f+1;i++)
	       qp->e[i] = qp->e[i+qp->f];
	    qp->f=0;
	    qp->r=i-1;
	}
	qp->e[++qp->r] = item;
}
item_type delete(queue* qp)
{
	if(isempty(qp))
	{
		puts("Queue is empty!");
		return 0;
	}	
	return qp->e[qp->f++];
}

item_type peek(queue* qp)
{
	if(isempty(qp))
	{
		puts("Queue is empty!");
		return 0;
	}	
	return qp->e[qp->f];
}

int size(queue*qp)
{
	return qp->r-qp->f+1;
}
void display(queue* qp)
{
  int i;
  for(i=qp->f;i<=qp->r;i++)
    printf("%d ",qp->e[i]);
}













