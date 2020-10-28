//sol3: Implementation of circular queue by leaving unused entry before front

#include<stdio.h>
#define MAX 5
typedef int item_type;

typedef struct
{
   item_type e[MAX];
   int f,r;
}queue;

void init(queue*);
void insert(queue*,item_type);
item_type delete(queue*);
item_type peek(queue*);
int size(queue*);
void display(queue*);
int isempty(queue*);
int isfull(queue*);

void init(queue* qp)
{
	qp->f = 0;
	qp->r = -1;
}
int isempty(queue* qp)
{
	return qp->f==(qp->r+1)%MAX;
}
  
int isfull(queue* qp)
{
   	return qp->f==(qp->r+2)%MAX;
}  

int size(queue* qp)
{
   if(qp->f<=qp->r || isempty(qp))	
   		return qp->r-qp->f+1;
	else
	    return qp->r+1 + MAX-1 -qp->f ;
}

void insert(queue* qp,item_type item)
{
	if(isfull(qp))
	{
		puts("Queue is Full!");
		return;
	}
	
	qp->r = (qp->r + 1)%MAX;
	qp->e[qp->r] = item;
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
item_type delete(queue* qp)
{
	item_type item;
	if(isempty(qp))
	{
		puts("Queue is empty!");
		return 0;
	}
	item = qp->e[qp->f];
	qp->f = (qp->f + 1)%MAX;
	return item;
}
 
void display(queue* qp)
{
	int i,n = size(qp);
	for(i=0;i<n;i++)
	   printf("%d ",qp->e[(qp->f+i)%MAX]);
}



















