#include "queue.h"

void initialize(queue *q,int size)
{
    q->rear=0;
    q->front=0;
    q->numitems=0;
    q->cap=size;
    q->items=malloc(size*sizeof(TYPE));
}

void enqueue(queue *q,TYPE value)
{
    q->items[q->rear++]=value;
    q->rear%=q->cap;
    q->numitems++;
}

TYPE dequeue(queue *q)
{
    q->front%=q->cap;
    q->numitems--;
    return q->items[q->front++];
}

int isfull(queue *q)
{
    return q->numitems==q->cap?1:0 ;
}

int isempty(queue *q)
{
    return q->numitems==0?1:0;
}

void dispose(queue *q)
{
    free(q->items);
}

int gethead(queue *q)
{
    queue copy;
    initialize(&copy,q->cap);
    int head=dequeue(q);
    enqueue(&copy,head);
    while(!isempty(q))
        enqueue(&copy,dequeue(q));
    while(!isempty(&copy))
        enqueue(q,dequeue(&copy));
    return head;
}
