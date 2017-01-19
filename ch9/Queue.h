//:Queue.h
//function:
//	using chained list to realize single queue
//program:
//	guo 2017.1.2 first release
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef int ElemType;
//#include "../AVLTree/AVLTree.h"
//typedef struct AVLNode * ElemType; 

struct Node;
struct QueueStruct;
typedef struct Node * PositionQ;
typedef struct QueueStruct * Queue;

Queue CreateQueue();
Queue PrElemTypeQueue(Queue Q);
ElemType Frontqueue(Queue Q);
Queue Dequeue(Queue Q);
Queue Enqueue(ElemType x,Queue Q);
int IsEmpty(Queue Q);

struct Node
{
    ElemType Element;
    struct Node * Next;
};

struct QueueStruct
{
    struct Node * Front;
    struct Node * Rear;
};
#endif//:Queue.h
