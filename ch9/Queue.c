//:Queue.c
#include "Queue.h"

int IsEmpty(Queue Q)
{
    if(Q->Front == NULL && Q->Rear == NULL)
   	return 1;
    else 
	return 0; 
}
Queue CreateQueue()
{
    Queue Q = (struct QueueStruct *)malloc(8);
    return Q;
}

Queue Enqueue(ElemType x,Queue Q)
{
    PositionQ tmp = malloc(sizeof(struct Node));
    tmp->Element = x;
    tmp->Next = NULL;
    if(Q->Front == NULL && Q->Rear == NULL)
    {
	Q->Front = tmp;
	Q->Rear = tmp;
    }
    else
    {
	Q->Rear->Next = tmp;
	Q->Rear = tmp;
    }
    return Q;
}

Queue Dequeue(Queue Q)
{
    if(Q->Front != NULL)
    {
    	PositionQ tmp = Q->Front;
	if(Q->Front == Q->Rear)
	{
	    Q->Front = NULL;
	    Q->Rear = NULL;
	}
	else 
	    Q->Front = Q->Front->Next;
	free(tmp);
    }
    return Q;
}

ElemType Frontqueue(Queue Q)
{
    if(Q->Front == NULL)
	return ;
    else 
	return Q->Front->Element;
}

Queue PrintQueue(Queue Q)
{
    PositionQ tmp = Q->Front;
    while(tmp != NULL)
    {
	printf("The element is: %d\n",tmp->Element);
	tmp = tmp->Next;
    }
    return Q;
}
