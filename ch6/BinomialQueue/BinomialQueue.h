//:BinomialQueue.h
//function:
//	Binomial queue is collection of heap trees, called forest
//	realize merge and deletemin
//program:
//	guo 2017/1/6 first released
//
#ifndef BINOMIALQUEUE_H
#define BINOMIALQUEUE_H

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;
#define MaxTrees 20
#define Capacity 1000

struct BinNode;
struct Collection;
typedef struct BinNode * Position;
typedef Position BinTree;
typedef struct Collection * BinQueue;

BinTree CombineTrees(BinTree T1,BinTree T2);

BinQueue Merge(BinQueue F1,BinQueue F2);

void PrintBinTree(int i,BinTree T);
void PrintBinQueue(BinQueue F);
BinQueue InsertBinQueue(ElemType x,BinQueue F);
BinQueue InsertBinQueueWithoutMerge(ElemType x,BinQueue F);
BinQueue CreateBinQueue();
int FindMin(BinQueue F);
ElemType DeleteMin(BinQueue F);

#endif //:BinomialQueue.h

struct BinNode
{
    ElemType Element; 
    Position LeftChild;
    Position NextSibling;
};

struct Collection
{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};
