//:BinHeap.h
//function:
//	realize binary heap Initialize Destroy Insert FindMin DeleteMin and so on
//program:
//	guo 2017/1/4 first released

#ifndef BINHEAP_H
#define BINHEAP_H
#include <stdio.h>
#include <malloc.h>

struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
typedef int ElemType;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElemType x,PriorityQueue H);
ElemType DeleteMin(PriorityQueue H);
ElemType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
void PrintBinHeap(PriorityQueue H);

#endif //:BinHeap.h

struct HeapStruct
{
    int Capacity;
    int Size;
    ElemType * Elements;
};
