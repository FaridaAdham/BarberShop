#ifndef qUEUE_H_INCLUDED
#define qUEUE_H_INCLUDED

#define TYPE int

typedef struct
{
    int front,rear,numitems;
    int cap;
    TYPE *items;
} queue;

void initialize(queue *q,int size) ;
void enqueue(queue *q,TYPE value) ;
TYPE dequeue(queue *q) ;
int isfull(queue *q) ;
int isempty(queue *q) ;
void dispose(queue *q);
int gethead(queue *q);

#endif // QUEUE_H_INCLUDED
